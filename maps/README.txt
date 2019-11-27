# [MAP FORMAT]
# With examples
# 
# Vertices_number: "V + space + number"
# Vertex:
# Y X
# Space(s) between values
#
V  6
0  0
0  15
15 0
15 15
0  30
15 30

# Emtpy line after vertices declaration
# Sectors_number: "S + space + number"
# Sectors:
# [floor_height floor_slope floor_texture align.x align.y scale.x scale.y] 
# Floor sprites:
# ([index pos.x pos.y scale.x scale.y][index pos.x pos.y scale.x scale.y]....)
# [ceiling_height ceiling_slope ceiling_texture align.x align.y scale.x scale.y]
# Ceiling sprites:
# ([index pos.x pos.y scale.x scale.y][index pos.x pos.y scale.x scale.y]....)
# (vertex_index in clockwise order)
# (neighbors_index in clockwise order) ('-1' = no neighbor)
# Textures:
# ([index align.x align.y scale.x scale.y] for every wall....)
# Wall sprites:
# ({[index pos.x pos.y scale.x scale.y] for every sprite on this wall...} for every wall..)
# light value between -255 and 255
# (0 to get the raw texture, negative values to darken and positive values to lighten)
# Space(s) between every section
#
S  2
[0  0  5 0 0 10 10] ([0 0 0 10 20])  [12 0 4 0 0 10 10] ([1 0 0 10 10])  (0 1 3 2)  (-1  1  -1 -1) ([0 0 0 10 10][1 0 0 10 10][2 0 0 10 10][3 0 0 10 10]) ({[-1 0 0 50 50]}{[-1 0 0 50 50]}{[-1 0 0 50 50]}{[-1 0 0 50 50]}) [0] [0 (0 0) (-1 0 0)]
[2  0  4 0 0 10 10] () [14 0 4 0 0 10 10] ()  (1 4 5 3)  (-1  -1  -1  0) ([0 0 0 10 10][1 0 0 10 10][2 0 0 10 10][3 0 0 10 10]) ({[1 0 5 2 2]}{}{}{}) [-150] [0 (0 0) (-1 0 0)]

# Emtpy line after sectors declaration
# Objects_number: "O + space + number"
# Object:
# [y x z angle] [sprite_number scale]
# Space(s) between every section
# Angle is ignored if the sprite is not oriented
#
O  1
[7.5 7.5 1 45] [0 50]

# Emtpy line after objects declaration
# Enemies_number: "E + space + number"
# Enemies:
# [y x z angle] [sprite_number scale] [health speed damage]
# spaces between each section
# speed should be between 0 and 1 (0 being static and 1 super fast)
#
E 1
[5 5 5 0] [1 50] [50 0.3 15]

# Empty line after enemies declaration
# Player:
# Y X angle
# One space between values
#
1  1   45
