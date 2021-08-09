#1/bin/bash

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

addRoute(){
	ip netns exec $1 ip route add $2 via $3 dev $4
}

addNS N1
addNS N2
addNS N3
addNS N4

addVethPeer v1 v2
addVethPeer v3 v4
addVethPeer v5 v6

setVethNS v1 N1
setVethNS v2 N2
setVethNS v3 N2
setVethNS v4 N3
setVethNS v5 N3
setVethNS v6 N4

setUpVeth N1 v1
setUpVeth N2 v2
setUpVeth N2 v3
setUpVeth N3 v4
setUpVeth N3 v5
setUpVeth N4 v6

setUpLo N1
setUpLo N2
setUpLo N3
setUpLo N4

addIP N1 10.0.10.47/24 v1
addIP N2 10.0.10.48/24 v2
addIP N2 10.0.20.47/24 v3
addIP N3 10.0.20.48/24 v4
addIP N3 10.0.30.47/24 v5
addIP N4 10.0.30.48/24 v6

addRoute N1 10.0.20.0/24 10.0.10.48 v1
addRoute N1 10.0.30.0/24 10.0.10.48 v1
addRoute N2 10.0.30.0/24 10.0.20.48 v3
addRoute N3 10.0.10.0/24 10.0.20.47 v4
addRoute N4 10.0.10.0/24 10.0.30.47 v6
addRoute N4 10.0.20.0/24 10.0.30.47 v6