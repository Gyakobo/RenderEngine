#ifndef INDEXBUFFER_H 
#define INDEXBUFFER_H

#include <iostream>
#include <GL/glew.h>

using namespace std;

class IndexBuffer {
private:
        GLuint BufferID;
	GLuint Count;
public:
        IndexBuffer(GLushort* data, GLsizei count);
    
        void bind() const;
        void unbind() const;

        inline GLuint getCount() const { return Count; }
};

#endif


