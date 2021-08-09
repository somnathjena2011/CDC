#!/bin/bash

addNS(){
	ip netns add $1
}

addVethPeer(){
	ip link add $1 type veth peer name $2
}

setVethNS(){
	ip link set $1 netns $2
}

setUpVeth(){
	ip netns exec $1 ip link set $2 up
}

setUpLo(){
	ip netns exec $1 ip link set lo up
}

addIP(){
	ip netns exec $1 ip addr add $2 dev $3
}

addDefault(){
	ip netns exec $1 ip route add default via $2
}

addNS H1
addNS H2
addNS H3
addNS R

addVethPeer veth1 veth2
addVethPeer veth3 veth6
addVethPeer veth4 veth5

setVethNS veth1 H1
setVethNS veth2 R
setVethNS veth3 R
setVethNS veth4 R
setVethNS veth5 H3
setVethNS veth6 H2

setUpVeth H1 veth1
setUpVeth H2 veth6
setUpVeth H3 veth5
setUpVeth R veth2
setUpVeth R veth3
setUpVeth R veth4

setUpLo H1
setUpLo H2
setUpLo H3
setUpLo R

addIP H1 10.0.10.47/24 veth1
addIP H2 10.0.20.47/24 veth6
addIP H3 10.0.30.47/24 veth5
addIP R 10.0.10.1/24 veth2
addIP R 10.0.20.1/24 veth3
addIP R 10.0.30.1/24 veth4

addDefault H1 10.0.10.47
addDefault H2 10.0.20.47
addDefault H3 10.0.30.47

bridgeExists=$(ip netns exec R brctl show | grep -c "bridge0")
if [[ $bridgeExists -gt 0 ]]
then
	ip netns exec R ip link delete bridge0 type bridge
fi

ip netns exec R brctl addbr bridge0

ip netns exec R brctl addif bridge0 veth2
ip netns exec R brctl addif bridge0 veth3
ip netns exec R brctl addif bridge0 veth4

ip netns exec R sysctl -wq net.ipv4.ip_forward=1

setUpVeth R bridge0