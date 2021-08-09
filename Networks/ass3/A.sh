#!/bin/bash

[[ -e /var/run/netns/ns1 ]] && ip netns del ns1
ip netns add ns1
[[ -e /var/run/netns/ns2 ]] && ip netns del ns2
ip netns add ns2

ip link add Veth0 type veth peer name Veth1

ip link set Veth0 netns ns1
ip link set Veth1 netns ns2

ip netns exec ns1 ip link set Veth0 up
ip netns exec ns2 ip link set Veth1 up

ip netns exec ns1 ip link set lo up
ip netns exec ns2 ip link set lo up

ip netns exec ns1 ip addr add 10.1.1.0/24 dev Veth0
ip netns exec ns2 ip addr add 10.1.2.0/24 dev Veth1

ip netns exec ns1 ip route add default via 10.1.1.0 dev Veth0
ip netns exec ns2 ip route add default via 10.1.2.0 dev Veth1