#include "textureMap.h"

unsigned int texture;
bool del = false;
int width, height;
glm::ivec3** image;
int delNum = 0;

void createTexture(){
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int nrChannels;
    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
    unsigned char *data = stbi_load("texture/a.png", &width, &height, &nrChannels, 0);


    if (data)
    {
        if(nrChannels == 3){
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        }else if(nrChannels == 4){
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        }else{
            cout << "ncrChannel error!" << endl;
        }
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    // create image array
    image = (glm::ivec3**)calloc(height, sizeof(glm::ivec3*));
    for(int i = 0; i < height; i++){
        image[i] = (glm::ivec3*)calloc(width, sizeof(glm::ivec3));
        for(int j = 0; j < width; j++){
            image[i][j].r = data[width*i + 3*j];
            image[i][j].g = data[width*i + 3*j + 1];
            image[i][j].b = data[width*i + 3*j + 2];
        }
        
    }
    cout << "Image " << height << " x " << width <<endl; 
    stbi_image_free(data);
}

void deleteTextureVoxel(std::vector<VoxData_b>&  bounderVoxelData, int bounderNum){

    double proportion_width = (double)width/ (double)map_width;
    double proportion_height = (double)height/ (double)map_height;
    // #pragma omp parallel
    // for(int i = 0; i < bounderNum; i++){
    for(int i = 1904; i < 1905; i++){
        // log_trace("%d",i);
        delNum = i;
        float x = bounderVoxelData[i].bounderVoxelLocate[0];
        float y = bounderVoxelData[i].bounderVoxelLocate[1];
        float z = bounderVoxelData[i].bounderVoxelLocate[2];
        glm::fvec3 point = {x, y, z};
        glm::fvec2 minLatticeCoord = {-1,-1};
        float minDist = 100;
        // cout << x << ", " << y << ", " << z <<endl;
        // Find the nearest lattice coordinates to this voxel
        for(int h = 0; h < map_height-1; h++){
            for(int w = 0; w < map_width-1; w++){
        // for(int h = 12; h < 14; h++){
        //     for(int w = 26; w < 28; w++){
                float t0_x, t0_y, t0_z;
                float t1_x, t1_y, t1_z;
                float t2_x, t2_y, t2_z;
                float t3_x, t3_y, t3_z;

                t0_x = lattice[h][w].x;
                t0_y = lattice[h][w].y;
                t0_z = lattice[h][w].z;
                glm::fvec3 t0 = {t0_x, t0_y, t0_z};

                t1_x = lattice[h][w+1].x;
                t1_y = lattice[h][w+1].y;
                t1_z = lattice[h][w+1].z;
                glm::fvec3 t1 = {t1_x, t1_y, t1_z};

                t2_x = lattice[h+1][w+1].x;
                t2_y = lattice[h+1][w+1].y;
                t2_z = lattice[h+1][w+1].z;
                glm::fvec3 t2 = {t2_x, t2_y, t2_z};

                t3_x = lattice[h+1][w].x;
                t3_y = lattice[h+1][w].y;
                t3_z = lattice[h+1][w].z;
                glm::fvec3 t3 = {t3_x, t3_y, t3_z};
                // cout << "t0 : " << t0.x<<", " << t0.y<<", "<<t0.z<<endl;
                // cout << "t1 : " << t1.x<<", " << t1.y<<", "<<t1.z<<endl;
                // cout << "t2 : " << t2.x<<", " << t2.y<<", "<<t2.z<<endl;
                // cout << "t3 : " << t3.x<<", " << t3.y<<", "<<t3.z<<endl;
                // cout << "h : " << h << ",w : " << w << endl;
                // one grid has two triangle
                minLatticeCoord = find_point(point, t0, t1, t3, minDist, minLatticeCoord,glm::fvec2{h, w}, 0);
                if(minDist == 0.0) continue;
                if(minLatticeCoord == glm::fvec2(-1, -1)){
                    cout << "mincoord0 : " <<minLatticeCoord.x << " " << minLatticeCoord.y << endl;
                    cout << "h : " << h << ", w : " << w<<endl;
                    cout << "error0 : find point" <<endl;
                }
                
                minLatticeCoord = find_point(point, t2, t3, t1, minDist, minLatticeCoord,glm::fvec2{h, w}, 1);
                if(minDist == 0.0) continue;
                if(minLatticeCoord == glm::fvec2(-1, -1)){
                    cout << "error1 : find point" <<endl;
                }
                
            }
        }

        // Find the texture map that corresponds to this point on the lattice
        int newi = minLatticeCoord.x* proportion_height;
        int newj = minLatticeCoord.y* proportion_width;
        // cout << "mincoord : " <<minLatticeCoord.x << " " << minLatticeCoord.y << endl;
        // cout << "minDIst : " << minDist << endl;
        // cout << "new i, j : " <<newi << ", "<<newj << endl;
        // cout << "image rgb : " << image[newi][newj].r << ", " << image[newi][newj].g << ", " << image[newi][newj].b << endl;
        if(image[newi][newj].r + image[newi][newj].g + image[newi][newj].b == 0){
            bounderVoxelData[i].show = 0;
            // cout << "del" << endl;
        }
    }
}

glm::fvec2 find_point(glm::fvec3 point, glm::fvec3 t0, glm::fvec3 t1, glm::fvec3 t2, float& minDist, glm::fvec2& mincoord, glm::fvec2 coord, int ud){
    float h = coord.x;
    float w = coord.y;

    // Calculate the normal vector of the plane in which the triangle is located
    glm::fvec3 n = cross_product(t1-t0, t2-t0);
    // cout <<"point : " << point.x<<", " << point.y<<", " << point.z<<endl;
    // cout << "t0 : " << t0.x<<", " << t0.y<<", "<<t0.z<<endl;
    // cout << "t1 : " << t1.x<<", " << t1.y<<", "<<t1.z<<endl;
    // cout << "t2 : " << t2.x<<", " << t2.y<<", "<<t2.z<<endl;
    // cout << "n : " << n.x<<", " << n.y<<", "<<n.z<<endl;

    // compute coordinate translate matrix 
    glm::mat3 coord_trans_matrix;
    coord_trans_matrix[0][0] = (t1-t0).x; coord_trans_matrix[0][1] = (t1-t0).y; coord_trans_matrix[0][2] = (t1-t0).z; 
    coord_trans_matrix[1][0] = (t2-t0).x; coord_trans_matrix[1][1] = (t2-t0).y; coord_trans_matrix[1][2] = (t2-t0).z; 
    coord_trans_matrix[2][0] = n.x; coord_trans_matrix[2][1] = n.y; coord_trans_matrix[2][2] = n.z; 

    // translate proj_point to other coordinate system
    glm::fvec3 triangle_base_point = glm::inverse(coord_trans_matrix)*(point-t0);
    // cout << "dist to t0 : " << distance(point-t0) << endl; 
    // cout << "dist to t1 : " << distance(point-t1) << endl; 
    // cout << "dist to t2 : " << distance(point-t2) << endl; 
    // Determine which of the seven blocks the point is in
    float x = triangle_base_point.x;
    float y = triangle_base_point.y;
    float z = triangle_base_point.z;
    // cout << x << " " << y << " " << z << endl;
    if(x+y < 1.0 && x > 0.0 && y > 0.0){
        // cout << "0" << endl;
        minDist = 0.0;
        return {h+x,w+y};
    }else if(x+y >= 1.0 && x > 0.0 && y <= 0.0){
        // cout << "1" << endl;
        float dist = distance(point-t2);
        if(minDist > dist|| mincoord == glm::fvec2(-1,-1)){
            minDist = dist;
            if(ud == 0) return {h+1,w};
            else return {h,w+1}; 
        }else{
            return mincoord;
        }
    }else if(x <= 0.0 && y <= 0.0){
        // cout << "2" << endl;
        float dist = distance(point-t0);
        if(minDist > dist|| mincoord == glm::fvec2(-1,-1)){
            minDist = dist;
            if(ud == 0) return {h,w};
            else return {h+1,w+1};   
        }else{
            return mincoord;
        }
    }else if(x+y >= 1.0 && x <= 0.0 && y >= 0.0){
        // cout << "3" << endl;
        float dist = distance(point-t1);
        if(minDist > dist|| mincoord == glm::fvec2(-1,-1)){
            minDist = dist;
            if(ud == 0) return {h,w+1};
            else return {h+1,w}; 
        }else{
            return mincoord;
        }
    }else if(x+y >= 1.0 && x >= 0.0 && y >= 0.0){
        // cout << "4" << endl;
        glm::fvec3 p = find_nearest_edge_point(triangle_base_point,glm::fvec3(1,0,0),glm::fvec3(0,1,0));
        float dist = distance(point-coord_trans_matrix*p);
        if(minDist > dist|| mincoord == glm::fvec2(-1,-1)){
            minDist = dist;
            if(ud == 0) return {h+p.x, w+p.y};
            else return {h+1-p.x, w+1-p.y};
        }else{
            return mincoord;
        }
    }else if(x+y < 1.0 && y <= 0.0 && x >= 0.0){
        // cout << "5" << endl;
        glm::fvec3 p = find_nearest_edge_point(triangle_base_point,glm::fvec3(0,0,0) , glm::fvec3(0,1,0));
        float dist = distance(point-coord_trans_matrix*p);
        if(minDist > dist|| mincoord == glm::fvec2(-1,-1)){
            minDist = dist;
            if(ud == 0) return {h+p.x, w+p.y};
            else return {h+1-p.x, w+1-p.y};
        }else{
            return mincoord;
        }
    }else if(x+y < 1.0 && x <= 0.0 && y >= 0.0){
        // cout << "6" << endl;
        glm::fvec3 p = find_nearest_edge_point(triangle_base_point, glm::fvec3(0,0,0),  glm::fvec3(1,0,0));
        float dist = distance(point-coord_trans_matrix*p);
        if(minDist > dist || mincoord == glm::fvec2(-1,-1)){
            minDist = dist;
            if(ud == 0) return {h+p.x, w+p.y};
            else return {h+1-p.x, w+1-p.y};
        }else{
            return mincoord;
        }
    }
    // cout << "coord : " << coord.x << "," << coord.y << endl;
    // cout <<"x,y,x : " << x << " " << y << " " << z << endl;
    return glm::fvec2(-1,-1);

}
glm::fvec3 cross_product(glm::fvec3 l1, glm::fvec3 l2){
    if(l1 == glm::fvec3(-1,-1,-1)*l2){
        return {0,0,0};
    }
    float c0 = l1.y*l2.z - l2.y*l1.z;
    float c1 = -1 * (l1.x*l2.z - l2.x*l1.z);
    float c2 = l1.x*l2.y - l2.x*l1.y;
    

    return {c0, c1, c2};
}
glm::fvec3 normalization(glm::fvec3 vector){
    float c = sqrt(vector.x*vector.x + vector.y*vector.y + vector.z*vector.z);
    return {vector.x/c, vector.y/c, vector.z/c};
}
float inner_product(glm::fvec3 l1, glm::fvec3 l2){
    return l1.x*l2.x + l1.y*l2.y + l1.z*l2.z;
}
float distance(glm::fvec3 len){
    return sqrt(len.x*len.x + len.y*len.y + len.z*len.z);
}
glm::fvec3 find_nearest_edge_point(glm::fvec3 point, glm::fvec3 t0, glm::fvec3 t1){
    float radio = inner_product(point-t0,t1-t0)/(distance(t1-t0)*distance(t1-t0));
    if(radio > 1.0) radio = 1.0;
    if(radio < -1.0) radio = -1.0;
    return (t0 + glm::fvec3(radio*(t1-t0).x , radio*(t1-t0).y, radio*(t1-t0).z));
}

glm::fvec2 lattice_coord(int h, int w, glm::fvec3 coord){
    float t0_x, t0_y, t0_z;
    float t1_x, t1_y, t1_z;
    float t2_x, t2_y, t2_z;
    float t3_x, t3_y, t3_z;

    t0_x = lattice[h][w].x;
    t0_y = lattice[h][w].y;
    t0_z = lattice[h][w].z;
    glm::fvec3 t0 = {t0_x, t0_y, t0_z};

    t1_x = lattice[h][w+1].x;
    t1_y = lattice[h][w+1].y;
    t1_z = lattice[h][w+1].z;
    glm::fvec3 t1 = {t1_x, t1_y, t1_z};

    t2_x = lattice[h+1][w+1].x;
    t2_y = lattice[h+1][w+1].y;
    t2_z = lattice[h+1][w+1].z;
    glm::fvec3 t2 = {t2_x, t2_y, t2_z};

    t3_x = lattice[h+1][w+1].x;
    t3_y = lattice[h+1][w+1].y;
    t3_z = lattice[h+1][w+1].z;
    glm::fvec3 t3 = {t3_x, t3_y, t3_z};


    glm::fvec3 wdir;
    glm::fvec3 hdir;
    // if(coord.w == 0){
    //     wdir = t1-t0;
    //     hdir = t2-t0;
    // }else{
    //     wdir = 
    // }

    // glm::fvec3 cross_1 = cross(wdir,hdir);
    // glm::fvec3 cross_2 = cross(t1-coord.xyz,t2-coord.xyz);
    // cout << cross_1.x << ", " << cross_1.y << ", " << cross_1.z<<endl;
    // cout << cross_2.x << ", " << cross_2.y << ", " << cross_2.z<<endl;


    if(coord == t0)return {h,w};
    if(coord == t1)return {h,w+1};
    if(coord == t2)return {h+1,w};

    float wradio = inner_product(coord, wdir)/(distance(wdir)*distance(wdir));
    float hradio = inner_product(coord, hdir)/(distance(hdir)*distance(hdir));
    cout << "radio : "<< wradio << ", " << hradio <<endl;
    return {h+hradio, w+wradio};
}