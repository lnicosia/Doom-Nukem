[MAP FORMAT]
With examples

# Vertices number: "V + space + number"
V 4
# vertices value: "Y + space(s) + X"
0 0
0 15
15 0
15 15

# Emtpy line after vertices declaration
# Sectors number: "S + space + number"
# Sectors: "floor height, floor slope, ceiling height, ceiling slope, then vertex numbers in clockwise order"
# After the list of vertexes comes the list of sector numbers on the "opposite" side of that wall; "-1" = none.
# You must separate vertex numbers from neighbors with a TAB
Sector	1
sector	0 0 20 0	0 1 3 2		-1 -1 -1 -1

# Player: Location (y x), angle, and sector number
player	1 1	0	0
