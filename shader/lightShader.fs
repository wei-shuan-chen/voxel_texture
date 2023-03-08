#version 330 core
out vec4 FragColor;

in VS_OUT{
    vec3 FragPos;
	vec3 Normal;
    vec3 Color;
	vec2 TexCoords;
} fs_in;

// uniform vec3 objectColor;
uniform vec3 lightPos;
uniform vec3 viewPos;
uniform bool shader;
uniform sampler2D t1;
// function prototypes
void main()
{
    if(shader){
        // ka,kd,ks   ia,id,is
        float ka = 0.3, kd = 0.8, ks = 0.5;
        vec3 Ia = vec3(0.3, 0.3, 0.3);
        vec3 Id = vec3(0.8, 0.8, 0.8);
        vec3 Is = vec3(0.8, 0.8, 0.8);
        // ambient
        vec3 ambient = ka * Ia;
        // diffuse
        vec3 L = normalize(lightPos - fs_in.FragPos);
        vec3 N = normalize(fs_in.Normal);
        vec3 diffuse = kd * Id * max(dot(L, N), 0.0);
        // specular
        vec3 V = normalize(viewPos - fs_in.FragPos);
        vec3 R = reflect(-L, N);
// blinn
// vec3 halfwayDir = normalize(L + V);  
// spec = pow(max(dot(N, halfwayDir), 0.0), 256.0);      
        vec3 specular = ks * Is * pow(max(dot(V, R), 0.0), 256.0); // assuming bright white light color
        vec3 I = vec3(ambient + diffuse + specular);
        // FragColor = vec4(0.0,0.0 , fs_in.Color.z, 1.0);
        FragColor = vec4(I.x*fs_in.Color.x, I.y*fs_in.Color.y, I.z*fs_in.Color.z, 1.0);
    }else{
        FragColor = texture(t1, fs_in.TexCoords);
        // FragColor = vec4(color, 1.0);
    }
    
} 
