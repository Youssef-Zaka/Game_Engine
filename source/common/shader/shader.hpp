#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>

#include <glad/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace our {

    class ShaderProgram {

    private:
        //Shader Program Handle
        GLuint program;

    public:
        void create();
        void destroy();

        ShaderProgram(){ program = 0; }
        ~ShaderProgram(){ destroy(); }
        ShaderProgram (const ShaderProgram & ) = delete;
        ShaderProgram & operator= (const ShaderProgram &) = delete;

        bool attach(const std::string &filename, GLenum type) const;

        bool link() const;

        void use() { 
            //TODO: call opengl to use the program identified by this->program
            glUseProgram(this->program);
            
        }

        GLuint getUniformLocation(const std::string &name) {
            //TODO: call opengl to get the uniform location for the uniform defined by name from this->program

            //c_str() returns a null terminated string array that represents the string it was called from
            return glGetUniformLocation(this->program,name.c_str());
        }

        void set(const std::string &uniform, GLfloat value) {
            // TODO: call opengl to set the value to the uniform defined by name

            //NOT SURE
            // glUniform1f requires the uniform location and the value to be set
            // we can get the location using getUniformLocation()
            // after this function, the uniform defined by the passed in uniform name will be set to value
            glUniform1f(getUniformLocation(uniform), value);
        }

        void set(const std::string &uniform, glm::vec2 value) {
            //TODO: call opengl to set the value to the uniform defined by name
            glUniform2f(getUniformLocation(uniform), value.x, value.y);
        }

        void set(const std::string &uniform, glm::vec3 value) {
            //TODO: call opengl to set the value to the uniform defined by name
            glUniform3f(getUniformLocation(uniform), value.x, value.y, value.z);
        }

        void set(const std::string &uniform, glm::vec4 value) {
            //TODO: call opengl to set the value to the uniform defined by name
            glUniform4f(getUniformLocation(uniform), value.x, value.y, value.z, value.w);

        }


        //TODO: Delete the copy constructor and assignment operator



        //Question: Why do we do this? Hint: Look at the deconstructor

        //BECAUSE THE DESTRUCTOR SETS THE PROGRAM TO 0 MEANING IT IS ILLOGICAL TO DO SO IN THE COPY CONSTRUCTOR

    };

}

#endif