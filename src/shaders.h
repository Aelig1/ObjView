// char** shader_source = { char* vertex_shader, char* fragment_shader };

namespace ObjView
{

namespace Shaders {
	
const char* basic_diffuse[] = {
"void main() {"
"	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;"
"}",
"void main() {"
"	gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);"
"}" };

const char* normal[] = {
"varying vec3 normal;"
"void main() {"
"	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;"
"	normal = gl_NormalMatrix * gl_Normal;"
"}",
"varying vec3 normal;"
"void main() {"
"	normal = 0.5 * normalize(normal) + vec3(0.5, 0.5, 0.5);"
"	gl_FragColor = vec4(normal, 1.0);"
"}" };

const char* depth[] = {
"void main() {"
"	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;"
"}",
"void main() {"
"	gl_FragColor = vec4(vec3(gl_FragCoord.z), 1.0);"
"}" };

}

}
