sudo ip netns add P1
sudo ip netns add P2
sudo ip netns add P3
sudo ip netns add P4

sudo ip link add v1 netns P1 type veth peer name v2 netns P4
sudo ip link add v3 netns P2 type veth peer name v4 netns P4
sudo ip link add v5 netns P3 type veth peer name v6 netns P4

sudo ip netns exec P1 ip addr add 10.0.10.57/24 dev v1
sudo ip netns exec P4 ip addr add 10.0.10.58/24 dev v2
sudo ip netns exec P2 ip addr add 10.0.20.57/24 dev v3
sudo ip netns exec P4 ip addr add 10.0.20.58/24 dev v4
sudo ip netns exec P3 ip addr add 10.0.30.57/24 dev v5
sudo ip netns exec P4 ip addr add 10.0.30.58/24 dev v6

sudo ip netns exec P1 ip link set v1 up
sudo ip netns exec P4 ip link set v2 up
sudo ip netns exec P2 ip link set v3 up
sudo ip netns exec P4 ip link set v4 up
sudo ip netns exec P3 ip link set v5 up
sudo ip netns exec P4 ip link set v6 up

sudo ip netns exec P4 sysctl -w net.ipv4.ip_forward=1

sudo ip netns exec P1 ip route add 10.0.20.0/24 via 10.0.10.58 dev v1
sudo ip netns exec P1 ip route add 10.0.30.0/24 via 10.0.10.58 dev v1
sudo ip netns exec P2 ip route add 10.0.10.0/24 via 10.0.20.58 dev v3
sudo ip netns exec P2 ip route add 10.0.30.0/24 via 10.0.20.58 dev v3
sudo ip netns exec P3 ip route add 10.0.10.0/24 via 10.0.30.58 dev v5
sudo ip netns exec P3 ip route add 10.0.20.0/24 via 10.0.30.58 dev v5