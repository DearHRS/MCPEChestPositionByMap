# MCPEChestPositionByMap
Gives exact position of chest after you get into chunk with treasure using treasure map

Programme find north west corner of chunk relative to your position and then adds +8 to x and z to give postion of chest
Programme also works for Java Edition of the game but their relative position is +9 to x and z, so coordinate will be off by 1block along x and z

north west corner of chunk was chosen because it is the only corner whose coordinates are divisible by 16
