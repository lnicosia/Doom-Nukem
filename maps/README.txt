# [MAP FORMAT]
# With examples
# 
# Vertices_number: "V + space + number"
# Vertex:
# Y X
# Space(s) between values
#
V 6
0.00000 -90.00000
0.00000 50.00000
50.00000 -90.00000
50.00000 50.00000
86.00000 -90.00000
86.00000 50.00000

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
S 2
[0.00000 0.00000 7 0.00000 0.00000 10.00000 10.00000] ([10 0.000000 0.000000 10.000000 10.000000][0 10.000000 10.000000 10.000000 10.000000][5 5.000000 5.000000 10.000000 10.000000]) [20.10000 0.00000 -1 0.00000 0.00000 10.00000 10.00000] ([1 20.000000 20.000000 10.000000 10.000000][0 20.000000 30.000000 10.000000 20.000000][0 20.000000 0.000000 10.000000 20.000000]) (0 1 3 2) (-1 -1 1 -1) (1 1 1 1) ([-1 0.000000 0.000000 10.000000 10.000000][4 0.000000 0.000000 10.000000 10.000000][7 0.000000 0.000000 10.000000 10.000000][7 0.000000 0.000000 10.000000 10.000000]) ({}{[5 4.000000 16.000000 2.000000 4.000000][7 8.000000 18.000000 2.000000 2.000000][13 12.000000 14.000000 2.000000 2.000000][16 16.000000 14.000000 2.000000 2.000000]}{}{}) [0 0 0 -9.810000]
[1.10000 -0.06000 7 -4.00000 0.00000 10.00000 10.00000] () [18.10000 0.00000 7 0.00000 0.00000 10.00000 10.00000] () (2 3 5 4) (0 -1 -1 -1) (1 1 1 1) ([7 0.000000 0.000000 10.000000 10.000000][7 0.000000 0.000000 10.000000 10.000000][7 0.000000 0.000000 10.000000 10.000000][7 0.000000 0.000000 10.000000 10.000000]) ({}{}{}{}) [-64 ffffffff 0 -9.810000]

# Emtpy line after sectors declaration
# Objects_number: "O + space + number"
# Object:
# [y x z angle] [sprite_number scale]
# Space(s) between every section
# Angle is ignored if the sprite is not oriented
#
O  1
[27.010 13.182 0.000 0.000] [11 2]

# Emtpy line after objects declaration
# Enemies_number: "E + space + number"
# Enemies:
# [y x z angle] [sprite_number scale] [health speed damage]
# spaces between each section
# speed should be between 0 and 1 (0 being static and 1 super fast)
#
E 1
[16 -69 0 0] [1 5] [40 40 25]

# Empty line after enemies declaration
# Events
[1 (0 1 2)][20 (0 1 2)][0 25 0.000000][][][0 0]
[1 (0 1 2)][20 (0 1 2)][0 24 0.000000][][][0 0]
[1 (0 1 2)][35 (0)][0 64 0.000000][][][0 0]
[1 (0 1 2)][35 (0)][0 0 0.000000][][][0 0]
Links

# Empty line after events links declaration
# Player:
# Y X angle
# One space between values
#
20.0 20.0 0
