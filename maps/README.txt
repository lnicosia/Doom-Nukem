[MAP FORMAT]
With example

# Vertexes (Y coordinate, followed by list of X coordinates)
Vertex	4
vertex	0 0
vertex	0 15
vertex	15 0
vertex	15 15

# Sectors (floor height, floor slope, ceiling height, ceiling slope, then vertex numbers in clockwise order)
# After the list of vertexes comes the list of sector numbers on the "opposite" side of that wall; "-1" = none.
# You must separate vertex numbers from neighbors with a TAB
Sector	1
sector	0 0 20 0	0 1 3 2		-1 -1 -1 -1

# Player: Location (y x), angle, and sector number
player	1 1	0	0
