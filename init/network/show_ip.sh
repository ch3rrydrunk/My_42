#!/usr/bin/sh
# Show IP broadcasting address (dis boi tells u, who is around)
ifconfig en0 | awk /broadcast/ | awk '{print $2}'
# Show all the IP addresses that are the part of my subnet
# arp -a | awk '{print $2}' | sed 's/[)()]//g'
