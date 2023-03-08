#include "world.h"

struct World world = {};

void create_world(std::vector<VoxData_b>  bounderVoxelData, int bounderNum,int* numVoxelFace) {
    world.cube = {
        //       position                  normal
        Vertex{  { 0.0f,  0.0f,  0.0f, } , { 0.0f,  0.0f, -1.0f} },
        Vertex{  { 1.0f,  0.0f,  0.0f, } , { 0.0f,  0.0f, -1.0f} },
        Vertex{  { 1.0f,  1.0f,  0.0f, } , { 0.0f,  0.0f, -1.0f} },
        Vertex{  { 1.0f,  1.0f,  0.0f, } , { 0.0f,  0.0f, -1.0f} },
        Vertex{  { 0.0f,  1.0f,  0.0f, } , { 0.0f,  0.0f, -1.0f} },
        Vertex{  { 0.0f,  0.0f,  0.0f, } , { 0.0f,  0.0f, -1.0f} },

        Vertex{  { 0.0f,  0.0f,  1.0f, } , { 0.0f,  0.0f,  1.0f} },
        Vertex{  { 1.0f,  0.0f,  1.0f, } , { 0.0f,  0.0f,  1.0f} },
        Vertex{  { 1.0f,  1.0f,  1.0f, } , { 0.0f,  0.0f,  1.0f} },
        Vertex{  { 1.0f,  1.0f,  1.0f, } , { 0.0f,  0.0f,  1.0f} },
        Vertex{  { 0.0f,  1.0f,  1.0f, } , { 0.0f,  0.0f,  1.0f} },
        Vertex{  { 0.0f,  0.0f,  1.0f, } , { 0.0f,  0.0f,  1.0f} },

        Vertex{  { 0.0f,  1.0f,  1.0f, } , {-1.0f,  0.0f,  0.0f} },
        Vertex{  { 0.0f,  1.0f,  0.0f, } , {-1.0f,  0.0f,  0.0f} },
        Vertex{  { 0.0f,  0.0f,  0.0f, } , {-1.0f,  0.0f,  0.0f} },
        Vertex{  { 0.0f,  0.0f,  0.0f, } , {-1.0f,  0.0f,  0.0f} },
        Vertex{  { 0.0f,  0.0f,  1.0f, } , {-1.0f,  0.0f,  0.0f} },
        Vertex{  { 0.0f,  1.0f,  1.0f, } , {-1.0f,  0.0f,  0.0f} },

        Vertex{  { 1.0f,  1.0f,  1.0f, } , { 1.0f,  0.0f,  0.0f} },
        Vertex{  { 1.0f,  1.0f,  0.0f, } , { 1.0f,  0.0f,  0.0f} },
        Vertex{  { 1.0f,  0.0f,  0.0f, } , { 1.0f,  0.0f,  0.0f} },
        Vertex{  { 1.0f,  0.0f,  0.0f, } , { 1.0f,  0.0f,  0.0f} },
        Vertex{  { 1.0f,  0.0f,  1.0f, } , { 1.0f,  0.0f,  0.0f} },
        Vertex{  { 1.0f,  1.0f,  1.0f, } , { 1.0f,  0.0f,  0.0f} },

        Vertex{  { 0.0f,  0.0f,  0.0f, } , { 0.0f, -1.0f,  0.0f} },
        Vertex{  { 1.0f,  0.0f,  0.0f, } , { 0.0f, -1.0f,  0.0f} },
        Vertex{  { 1.0f,  0.0f,  1.0f, } , { 0.0f, -1.0f,  0.0f} },
        Vertex{  { 1.0f,  0.0f,  1.0f, } , { 0.0f, -1.0f,  0.0f} },
        Vertex{  { 0.0f,  0.0f,  1.0f, } , { 0.0f, -1.0f,  0.0f} },
        Vertex{  { 0.0f,  0.0f,  0.0f, } , { 0.0f, -1.0f,  0.0f} },

        Vertex{  { 0.0f,  1.0f,  0.0f, } , { 0.0f,  1.0f,  0.0f} },
        Vertex{  { 1.0f,  1.0f,  0.0f, } , { 0.0f,  1.0f,  0.0f} },
        Vertex{  { 1.0f,  1.0f,  1.0f, } , { 0.0f,  1.0f,  0.0f} },
        Vertex{  { 1.0f,  1.0f,  1.0f, } , { 0.0f,  1.0f,  0.0f} },
        Vertex{  { 0.0f,  1.0f,  1.0f, } , { 0.0f,  1.0f,  0.0f} },
        Vertex{  { 0.0f,  1.0f,  0.0f, } , { 0.0f,  1.0f,  0.0f} },
    };
  
    for(int i = 0; i < bounderNum; i++){
        int x = bounderVoxelData[i].bounderVoxelLocate.x;
        int y = bounderVoxelData[i].bounderVoxelLocate.y;
        int z = bounderVoxelData[i].bounderVoxelLocate.z;
        if(bounderVoxelData[i].bounderVoxelFaceAir[0] == 0){//0
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  0.0f + y,  0.0f + z, } , { 0.0f,  0.0f, -1.0f}, { 1.0f,  0.0f, 0.0f} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  0.0f + y,  0.0f + z, } , { 0.0f,  0.0f, -1.0f}, { 1.0f,  0.0f, 0.0f} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  1.0f + y,  0.0f + z, } , { 0.0f,  0.0f, -1.0f}, { 1.0f,  0.0f, 0.0f} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  1.0f + y,  0.0f + z, } , { 0.0f,  0.0f, -1.0f}, { 1.0f,  0.0f, 0.0f} });
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  1.0f + y,  0.0f + z, } , { 0.0f,  0.0f, -1.0f}, { 1.0f,  0.0f, 0.0f} });
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  0.0f + y,  0.0f + z, } , { 0.0f,  0.0f, -1.0f}, { 1.0f,  0.0f, 0.0f} });
            (*numVoxelFace)++;
        }
        if(bounderVoxelData[i].bounderVoxelFaceAir[1] == 0){//1
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  0.0f + y,  1.0f + z, } , { 0.0f,  0.0f,  1.0f}, { 1.0f,  0.0f, 0.0f} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  0.0f + y,  1.0f + z, } , { 0.0f,  0.0f,  1.0f}, { 1.0f,  0.0f, 0.0f} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  1.0f + y,  1.0f + z, } , { 0.0f,  0.0f,  1.0f}, { 1.0f,  0.0f, 0.0f} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  1.0f + y,  1.0f + z, } , { 0.0f,  0.0f,  1.0f}, { 1.0f,  0.0f, 0.0f} });
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  1.0f + y,  1.0f + z, } , { 0.0f,  0.0f,  1.0f}, { 1.0f,  0.0f, 0.0f} });
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  0.0f + y,  1.0f + z, } , { 0.0f,  0.0f,  1.0f}, { 1.0f,  0.0f, 0.0f} });
            (*numVoxelFace)++;
        }
        if(bounderVoxelData[i].bounderVoxelFaceAir[4] == 0){//2
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  1.0f + y,  1.0f + z, } , {-1.0f,  0.0f,  0.0f}, { 1.0f,  0.0f, 0.0f} });
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  1.0f + y,  0.0f + z, } , {-1.0f,  0.0f,  0.0f}, { 1.0f,  0.0f, 0.0f} });
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  0.0f + y,  0.0f + z, } , {-1.0f,  0.0f,  0.0f}, { 1.0f,  0.0f, 0.0f} });
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  0.0f + y,  0.0f + z, } , {-1.0f,  0.0f,  0.0f}, { 1.0f,  0.0f, 0.0f} });
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  0.0f + y,  1.0f + z, } , {-1.0f,  0.0f,  0.0f}, { 1.0f,  0.0f, 0.0f} });
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  1.0f + y,  1.0f + z, } , {-1.0f,  0.0f,  0.0f}, { 1.0f,  0.0f, 0.0f} });
            (*numVoxelFace)++;
        }
        if(bounderVoxelData[i].bounderVoxelFaceAir[5] == 0){//3
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  1.0f + y,  1.0f + z, } , { 1.0f,  0.0f,  0.0f}, { 1.0f,  0.0f, .0f} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  1.0f + y,  0.0f + z, } , { 1.0f,  0.0f,  0.0f}, { 1.0f,  0.0f, .0f} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  0.0f + y,  0.0f + z, } , { 1.0f,  0.0f,  0.0f}, { 1.0f,  0.0f, .0f} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  0.0f + y,  0.0f + z, } , { 1.0f,  0.0f,  0.0f}, { 1.0f,  0.0f, .0f} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  0.0f + y,  1.0f + z, } , { 1.0f,  0.0f,  0.0f}, { 1.0f,  0.0f, .0f} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  1.0f + y,  1.0f + z, } , { 1.0f,  0.0f,  0.0f}, { 1.0f,  0.0f, .0f} });
            (*numVoxelFace)++;
        }
        if(bounderVoxelData[i].bounderVoxelFaceAir[2] == 0){//4
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  0.0f + y,  0.0f + z, } , { 0.0f, -1.0f,  0.0f}, { 1.0f,  0.0f, 0.0f} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  0.0f + y,  0.0f + z, } , { 0.0f, -1.0f,  0.0f}, { 1.0f,  0.0f, 0.0f} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  0.0f + y,  1.0f + z, } , { 0.0f, -1.0f,  0.0f}, { 1.0f,  0.0f, 0.0f} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  0.0f + y,  1.0f + z, } , { 0.0f, -1.0f,  0.0f}, { 1.0f,  0.0f, 0.0f} });
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  0.0f + y,  1.0f + z, } , { 0.0f, -1.0f,  0.0f}, { 1.0f,  0.0f, 0.0f} });
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  0.0f + y,  0.0f + z, } , { 0.0f, -1.0f,  0.0f}, { 1.0f,  0.0f, 0.0f} });
            (*numVoxelFace)++;
        }
        if(bounderVoxelData[i].bounderVoxelFaceAir[3] == 0){//5
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  1.0f + y,  0.0f + z, } , { 0.0f,  1.0f,  0.0f}, { 1.0f,  0.0f, 0.0f} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  1.0f + y,  0.0f + z, } , { 0.0f,  1.0f,  0.0f}, { 1.0f,  0.0f, 0.0f} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  1.0f + y,  1.0f + z, } , { 0.0f,  1.0f,  0.0f}, { 1.0f,  0.0f, 0.0f} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  1.0f + y,  1.0f + z, } , { 0.0f,  1.0f,  0.0f}, { 1.0f,  0.0f, 0.0f} });
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  1.0f + y,  1.0f + z, } , { 0.0f,  1.0f,  0.0f}, { 1.0f,  0.0f, 0.0f} });
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  1.0f + y,  0.0f + z, } , { 0.0f,  1.0f,  0.0f}, { 1.0f,  0.0f, 0.0f} });
            (*numVoxelFace)++;
        }
    }
    
    for (int i = 0; i < map_width-1; i++)
    {
        for (int j = 0; j < map_height-1; j++)
        {
            float i_tex = (float)i / (float)(map_width-2);
            float i1_tex = (float)(i+1) / (float)(map_width-2);
            float j_tex = (float)j / (float)(map_width-2);
            float j1_tex = (float)(j+1) / (float)(map_width-2);

            world.lattice_square_four_edges.push_back(Vertex{ {lattice[i][j].x, lattice[i][j].y, lattice[i][j].z}, {0.0f, 0.0f, 0.0f}, { 1.0f,  1.0f, 1.0f}, {i_tex, j_tex}});
            world.lattice_square_four_edges.push_back(Vertex{ {lattice[i+1][j].x, lattice[i+1][j].y, lattice[i+1][j].z}, {0.0f, 0.0f, 0.0f}, { 1.0f,  1.0f, 1.0f}, {i1_tex, j_tex}});

            world.lattice_square_four_edges.push_back(Vertex{ {lattice[i+1][j].x, lattice[i+1][j].y, lattice[i+1][j].z}, {0.0f, 0.0f, 0.0f}, { 1.0f,  1.0f, 1.0f}, {i1_tex, j_tex}});
            world.lattice_square_four_edges.push_back(Vertex{ {lattice[i+1][j+1].x, lattice[i+1][j+1].y, lattice[i+1][j+1].z}, {0.0f, 0.0f, 0.0f}, { 1.0f,  1.0f, 1.0f}, {i1_tex, j1_tex}});

            world.lattice_square_four_edges.push_back(Vertex{ {lattice[i+1][j+1].x, lattice[i+1][j+1].y, lattice[i+1][j+1].z}, {0.0f, 0.0f, 0.0f}, { 1.0f,  1.0f, 1.0f}, {i1_tex, j1_tex}});
            world.lattice_square_four_edges.push_back(Vertex{ {lattice[i][j+1].x, lattice[i][j+1].y, lattice[i][j+1].z}, {0.0f, 0.0f, 0.0f}, { 1.0f,  1.0f, 1.0f}, {i_tex, j1_tex}});

            world.lattice_square_four_edges.push_back(Vertex{ {lattice[i][j+1].x, lattice[i][j+1].y, lattice[i][j+1].z}, {0.0f, 0.0f, 0.0f}, { 1.0f,  1.0f, 1.0f}, {i_tex, j1_tex}});
            world.lattice_square_four_edges.push_back(Vertex{ {lattice[i][j].x, lattice[i][j].y, lattice[i][j].z}, {0.0f, 0.0f, 0.0f}, { 1.0f,  1.0f, 1.0f}, {i_tex, j_tex}});
            
        }
    }
    for (int i = 0; i < map_width-1; i++)
    {
        for (int j = 0; j < map_height-1; j++)
        {
            float i_tex = (float)i / (float)(map_width-2);
            float i1_tex = (float)(i+1) / (float)(map_width-2);
            float j_tex = (float)j / (float)(map_width-2);
            float j1_tex = (float)(j+1) / (float)(map_width-2);

            world.tryy.push_back(Vertex{ {lattice[i][j].x, lattice[i][j].y, lattice[i][j].z}, {0.0f, 0.0f, 0.0f}, { 1.0f,  1.0f, 1.0f}, {i_tex, j_tex}});
            world.tryy.push_back(Vertex{ {lattice[i+1][j].x, lattice[i+1][j].y, lattice[i+1][j].z}, {0.0f, 0.0f, 0.0f}, { 1.0f,  1.0f, 1.0f}, {i1_tex, j_tex}});
            world.tryy.push_back(Vertex{ {lattice[i+1][j+1].x, lattice[i+1][j+1].y, lattice[i+1][j+1].z}, {0.0f, 0.0f, 0.0f}, { 1.0f,  1.0f, 1.0f}, {i1_tex, j1_tex}});

            world.tryy.push_back(Vertex{ {lattice[i+1][j+1].x, lattice[i+1][j+1].y, lattice[i+1][j+1].z}, {0.0f, 0.0f, 0.0f}, { 1.0f,  1.0f, 1.0f}, {i1_tex, j1_tex}});
            world.tryy.push_back(Vertex{ {lattice[i][j+1].x, lattice[i][j+1].y, lattice[i][j+1].z}, {0.0f, 0.0f, 0.0f}, { 1.0f,  1.0f, 1.0f}, {i_tex, j1_tex}});
            world.tryy.push_back(Vertex{ {lattice[i][j].x, lattice[i][j].y, lattice[i][j].z}, {0.0f, 0.0f, 0.0f}, { 1.0f,  1.0f, 1.0f}, {i_tex, j_tex}});
            
        }
    }
    // world.square = {
    //         Vertex{ { 0.0f, 0.0f, 0.0f}, { 0.0f,  1.0f,  0.0f}, {0.0f, 0.0f}},
    //         Vertex{ { 1.0f, 0.0f, 0.0f}, { 0.0f,  1.0f,  0.0f}, {1.0f, 0.0f}},
    //         Vertex{ { 1.0f, 0.0f, 1.0f}, { 0.0f,  1.0f,  0.0f}, {1.0f, 1.0f}},

    //         Vertex{ { 1.0f, 0.0f, 1.0f}, { 0.0f,  1.0f,  0.0f}, {1.0f, 1.0f}},
    //         Vertex{ { 0.0f, 0.0f, 1.0f}, { 0.0f,  1.0f,  0.0f}, {0.0f, 1.0f}},
    //         Vertex{ { 0.0f, 0.0f, 0.0f}, { 0.0f,  1.0f,  0.0f}, {0.0f, 0.0f}},
    // };
    world.square = {
            Vertex{ { 0.0f, 0.0f, 0.0f}, { 0.0f,  1.0f,  0.0f}, {0.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
            Vertex{ { 1.0f, 0.0f, 0.0f}, { 0.0f,  1.0f,  0.0f}, {0.0f, 1.0f, 1.0f}, {1.0f, 0.0f}},
            Vertex{ { 1.0f, 0.0f, 1.0f}, { 0.0f,  1.0f,  0.0f}, {0.0f, 1.0f, 1.0f}, {1.0f, 1.0f}},

            Vertex{ { 1.0f, 0.0f, 1.0f}, { 0.0f,  1.0f,  0.0f}, {0.0f, 1.0f, 1.0f}, {1.0f, 1.0f}},
            Vertex{ { 0.0f, 0.0f, 1.0f}, { 0.0f,  1.0f,  0.0f}, {0.0f, 1.0f, 1.0f}, {0.0f, 1.0f}},
            Vertex{ { 0.0f, 0.0f, 0.0f}, { 0.0f,  1.0f,  0.0f}, {0.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
    };
    world.squ_indices = {
        0, 1, 2, // first triangle
        0, 2, 3  // second triangle
    };
    world.tri= {
		Vertex{ { 0.5f, -0.5f, 0.0f}},
        Vertex{ {-0.5f, -0.5f, 0.0f}},
        Vertex{ { 0.0f,  0.5f, 0.0f}}
	};
}
void renew_world(){
    world.lattice_square_four_edges.clear(); 
    world.tryy.clear(); 

    for(int i = 0; i < map_width-1; i++){
        for(int j = 0; j < map_height-1; j++){
    // for(int i = 12; i < 14; i++){
    //     for(int j = 26; j < 28; j++){
            float i_tex = (float)i / (float)(map_width-2);
            float i1_tex = (float)(i+1) / (float)(map_width-2);
            float j_tex = (float)j / (float)(map_width-2);
            float j1_tex = (float)(j+1) / (float)(map_width-2);

            world.lattice_square_four_edges.push_back(Vertex{ {lattice[i][j].x, lattice[i][j].y, lattice[i][j].z}, {0.0f, 0.0f, 0.0f}, { 1.0f,  1.0f, 1.0f},  {i_tex, j_tex}});
            world.lattice_square_four_edges.push_back(Vertex{ {lattice[i+1][j].x, lattice[i+1][j].y, lattice[i+1][j].z}, {0.0f, 0.0f, 0.0f}, { 1.0f,  1.0f, 1.0f},  {i1_tex, j_tex}});

            world.lattice_square_four_edges.push_back(Vertex{ {lattice[i+1][j].x, lattice[i+1][j].y, lattice[i+1][j].z}, {0.0f, 0.0f, 0.0f}, { 1.0f,  1.0f, 1.0f},  {i1_tex, j_tex}});
            world.lattice_square_four_edges.push_back(Vertex{ {lattice[i+1][j+1].x, lattice[i+1][j+1].y, lattice[i+1][j+1].z}, {0.0f, 0.0f, 0.0f}, { 1.0f,  1.0f, 1.0f},  {i1_tex, j1_tex}});

            world.lattice_square_four_edges.push_back(Vertex{ {lattice[i+1][j+1].x, lattice[i+1][j+1].y, lattice[i+1][j+1].z}, {0.0f, 0.0f, 0.0f},  { 1.0f,  1.0f, 1.0f}, {i1_tex, j1_tex}});
            world.lattice_square_four_edges.push_back(Vertex{ {lattice[i][j+1].x, lattice[i][j+1].y, lattice[i][j+1].z}, {0.0f, 0.0f, 0.0f}, { 1.0f,  1.0f, 1.0f},  {i_tex, j1_tex}});

            world.lattice_square_four_edges.push_back(Vertex{ {lattice[i][j+1].x, lattice[i][j+1].y, lattice[i][j+1].z}, {0.0f, 0.0f, 0.0f}, { 1.0f,  1.0f, 1.0f},  {i_tex, j1_tex}});
            world.lattice_square_four_edges.push_back(Vertex{ {lattice[i][j].x, lattice[i][j].y, lattice[i][j].z}, {0.0f, 0.0f, 0.0f}, { 1.0f,  1.0f, 1.0f},  {i_tex, j_tex}});


            world.tryy.push_back(Vertex{ {lattice[i][j].x, lattice[i][j].y, lattice[i][j].z}, {0.0f, 0.0f, 0.0f}, { 1.0f,  1.0f, 1.0f},  {i_tex, j_tex}});
            world.tryy.push_back(Vertex{ {lattice[i+1][j].x, lattice[i+1][j].y, lattice[i+1][j].z}, {0.0f, 0.0f, 0.0f}, { 1.0f,  1.0f, 1.0f},  {i1_tex, j_tex}});
            world.tryy.push_back(Vertex{ {lattice[i+1][j+1].x, lattice[i+1][j+1].y, lattice[i+1][j+1].z}, {0.0f, 0.0f, 0.0f}, { 1.0f,  1.0f, 1.0f},  {i1_tex, j1_tex}});

            world.tryy.push_back(Vertex{ {lattice[i+1][j+1].x, lattice[i+1][j+1].y, lattice[i+1][j+1].z}, {0.0f, 0.0f, 0.0f}, { 1.0f,  1.0f, 1.0f},  {i1_tex, j1_tex}});
            world.tryy.push_back(Vertex{ {lattice[i][j+1].x, lattice[i][j+1].y, lattice[i][j+1].z}, {0.0f, 0.0f, 0.0f}, { 1.0f,  1.0f, 1.0f},  {i_tex, j1_tex}});
            world.tryy.push_back(Vertex{ {lattice[i][j].x, lattice[i][j].y, lattice[i][j].z}, {0.0f, 0.0f, 0.0f}, { 1.0f,  1.0f, 1.0f}, {i_tex, j_tex}});
            
        }
    }

     
}
void renew_del_world(std::vector<VoxData_b>  bounderVoxelData, int bounderNum,int* numVoxelFace){
    world.voxelBall.clear();
    // for(int i = 0; i < bounderNum; i++){
    for(int i = 1903; i < 1904; i++){
        int x = bounderVoxelData[i].bounderVoxelLocate.x;
        int y = bounderVoxelData[i].bounderVoxelLocate.y;
        int z = bounderVoxelData[i].bounderVoxelLocate.z;
        float c = bounderVoxelData[i].show;
        // cout << c << " " << i<<endl;// 5011 1,5013 1
        if(bounderVoxelData[i].bounderVoxelFaceAir[0] == 0 ){//0
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  0.0f + y,  0.0f + z, } , { 0.0f,  0.0f, -1.0f} , {c, c, c} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  0.0f + y,  0.0f + z, } , { 0.0f,  0.0f, -1.0f} , {c, c, c} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  1.0f + y,  0.0f + z, } , { 0.0f,  0.0f, -1.0f} , {c, c, c} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  1.0f + y,  0.0f + z, } , { 0.0f,  0.0f, -1.0f} , {c, c, c} });
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  1.0f + y,  0.0f + z, } , { 0.0f,  0.0f, -1.0f} , {c, c, c} });
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  0.0f + y,  0.0f + z, } , { 0.0f,  0.0f, -1.0f} , {c, c, c} });
            (*numVoxelFace)++;
        }
        if(bounderVoxelData[i].bounderVoxelFaceAir[1] == 0){//1
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  0.0f + y,  1.0f + z, } , { 0.0f,  0.0f,  1.0f} , {c, c, c} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  0.0f + y,  1.0f + z, } , { 0.0f,  0.0f,  1.0f} , {c, c, c} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  1.0f + y,  1.0f + z, } , { 0.0f,  0.0f,  1.0f} , {c, c, c} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  1.0f + y,  1.0f + z, } , { 0.0f,  0.0f,  1.0f} , {c, c, c} });
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  1.0f + y,  1.0f + z, } , { 0.0f,  0.0f,  1.0f} , {c, c, c} });
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  0.0f + y,  1.0f + z, } , { 0.0f,  0.0f,  1.0f} , {c, c, c} });
            (*numVoxelFace)++;
        }
        if(bounderVoxelData[i].bounderVoxelFaceAir[4] == 0){//2

            world.voxelBall.push_back(Vertex{  { 0.0f + x,  1.0f + y,  1.0f + z, } , {-1.0f,  0.0f,  0.0f} , {c, c, c} });
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  1.0f + y,  0.0f + z, } , {-1.0f,  0.0f,  0.0f} , {c, c, c} });
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  0.0f + y,  0.0f + z, } , {-1.0f,  0.0f,  0.0f} , {c, c, c} });
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  0.0f + y,  0.0f + z, } , {-1.0f,  0.0f,  0.0f} , {c, c, c} });
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  0.0f + y,  1.0f + z, } , {-1.0f,  0.0f,  0.0f} , {c, c, c} });
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  1.0f + y,  1.0f + z, } , {-1.0f,  0.0f,  0.0f} , {c, c, c} });
            (*numVoxelFace)++;
        }
        if(bounderVoxelData[i].bounderVoxelFaceAir[5] == 0){//3
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  1.0f + y,  1.0f + z, } , { 1.0f,  0.0f,  0.0f} , {c, c, c} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  1.0f + y,  0.0f + z, } , { 1.0f,  0.0f,  0.0f} , {c, c, c}});
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  0.0f + y,  0.0f + z, } , { 1.0f,  0.0f,  0.0f} , {c, c, c} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  0.0f + y,  0.0f + z, } , { 1.0f,  0.0f,  0.0f} , {c, c, c} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  0.0f + y,  1.0f + z, } , { 1.0f,  0.0f,  0.0f} , {c, c, c} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  1.0f + y,  1.0f + z, } , { 1.0f,  0.0f,  0.0f} , {c, c, c} });
            (*numVoxelFace)++;
        }
        if(bounderVoxelData[i].bounderVoxelFaceAir[2] == 0){//4
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  0.0f + y,  0.0f + z, } , { 0.0f, -1.0f,  0.0f} , {c, c, c} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  0.0f + y,  0.0f + z, } , { 0.0f, -1.0f,  0.0f} , {c, c, c} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  0.0f + y,  1.0f + z, } , { 0.0f, -1.0f,  0.0f} , {c, c, c} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  0.0f + y,  1.0f + z, } , { 0.0f, -1.0f,  0.0f} , {c, c, c} });
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  0.0f + y,  1.0f + z, } , { 0.0f, -1.0f,  0.0f} , {c, c, c}});
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  0.0f + y,  0.0f + z, } , { 0.0f, -1.0f,  0.0f} , {c, c, c} });
            (*numVoxelFace)++;
        }
        if(bounderVoxelData[i].bounderVoxelFaceAir[3] == 0){//5
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  1.0f + y,  0.0f + z, } , { 0.0f,  1.0f,  0.0f} , {c, c, c} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  1.0f + y,  0.0f + z, } , { 0.0f,  1.0f,  0.0f} , {c, c, c} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  1.0f + y,  1.0f + z, } , { 0.0f,  1.0f,  0.0f} , {c, c, c} });
            world.voxelBall.push_back(Vertex{  { 1.0f + x,  1.0f + y,  1.0f + z, } , { 0.0f,  1.0f,  0.0f} , {c, c, c} });
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  1.0f + y,  1.0f + z, } , { 0.0f,  1.0f,  0.0f} , {c, c, c} });
            world.voxelBall.push_back(Vertex{  { 0.0f + x,  1.0f + y,  0.0f + z, } , { 0.0f,  1.0f,  0.0f} , {c, c, c} });
            (*numVoxelFace)++;
        }
    }
}
void destroy_world() {
    world.lattice_square_four_edges.clear(); 
    world.voxelBall.clear();
    world.square.clear();
    world.squ_indices.clear();
    world.tri.clear();
    world.cube.clear();
}