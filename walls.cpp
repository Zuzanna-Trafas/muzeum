
#include "walls.h"

namespace Models {

    Walls walls;

    Walls::Walls() {
        vertices = WallsInternal::vertices;
        normals = WallsInternal::normals;
        vertexNormals = WallsInternal::vertexNormals;
        texCoords = WallsInternal::texCoords;
        colors = WallsInternal::colors;
        vertexCount = WallsInternal::vertexCount;
    }

    Walls::~Walls() {
    }

    void Walls::drawSolid(bool smooth) {
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);
        glEnableVertexAttribArray(3);


        glVertexAttribPointer(0, 4, GL_FLOAT, false, 0, vertices);
        if (!smooth) glVertexAttribPointer(1, 4, GL_FLOAT, false, 0, normals);
        else glVertexAttribPointer(1, 4, GL_FLOAT, false, 0, vertexNormals);
        glVertexAttribPointer(2, 4, GL_FLOAT, false, 0, texCoords);
        glVertexAttribPointer(3, 4, GL_FLOAT, false, 0, colors);

        glDrawArrays(GL_TRIANGLES, 0, vertexCount);

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(2);
        glDisableVertexAttribArray(3);
    }

    void Walls::drawWalls(GLuint tex) {
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 4, GL_FLOAT, false, 0, vertices);

        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 4, GL_FLOAT, false, 0, normals);

        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 2, GL_FLOAT, false, 0, texCoords);

        glEnableVertexAttribArray(3);
        glVertexAttribPointer(3, 4, GL_FLOAT, false, 0, colors);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, tex);

        glEnableVertexAttribArray(4);
        glUniform1i(4, 0);

        glDrawArrays(GL_TRIANGLES, 0, vertexCount);

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(2);
        glDisableVertexAttribArray(3);
        glDisableVertexAttribArray(4);
    }

    namespace WallsInternal {
        unsigned int vertexCount = 84;

        float vertices[] = {
                -0.15f, -1.0f, -1.0f, 1.0f,
                -1.0f, 1.0f, -1.0f, 1.0f,
                -1.0f, -1.0f, -1.0f, 1.0f,

                -0.15f, -1.0f, -1.0f, 1.0f,
                -0.15f, 1.0f, -1.0f, 1.0f,
                -1.0f, 1.0f, -1.0f, 1.0f,

                1.0f, -1.0f, -1.0f, 1.0f,
                0.15f, 1.0f, -1.0f, 1.0f,
                0.15f, -1.0f, -1.0f, 1.0f,

                1.0f, -1.0f, -1.0f, 1.0f,
                1.0f, 1.0f, -1.0f, 1.0f,
                0.15f, 1.0f, -1.0f, 1.0f,


                0.15f, 0.5f, -1.0f, 1.0f,
                -0.15f, 1.0f, -1.0f, 1.0f,
                -0.15f, 0.5f, -1.0f, 1.0f,

                0.15f, 0.5f, -1.0f, 1.0f,
                0.15f, 1.0f, -1.0f, 1.0f,
                -0.15f, 1.0f, -1.0f, 1.0f,


                -1.0f, -1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, -1.0f, 1.0f, 1.0f,

                -1.0f, -1.0f, 1.0f, 1.0f,
                -1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f,



                1.0f, -1.0f, -0.15f, 1.0f,
                1.0f, 1.0f, -1.0f, 1.0f,
                1.0f, -1.0f, -1.0f, 1.0f,

                1.0f, -1.0f, -0.15f, 1.0f,
                1.0f, 1.0f, -0.15f, 1.0f,
                1.0f, 1.0f, -1.0f, 1.0f,


                1.0f, -1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 0.15f, 1.0f,
                1.0f, -1.0f, 0.15f, 1.0f,

                1.0f, -1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 0.15f, 1.0f,


                1.0f, 0.5f, 0.15f, 1.0f,
                1.0f, 1.0f, -0.15f, 1.0f,
                1.0f, 0.5f, -0.15f, 1.0f,

                1.0f, 0.5f, 0.15f, 1.0f,
                1.0f, 1.0f, 0.15f, 1.0f,
                1.0f, 1.0f, -0.15f, 1.0f,

                -1.0f, -1.0f, -1.0f, 1.0f,
                -1.0f, 1.0f, 1.0f, 1.0f,
                -1.0f, -1.0f, 1.0f, 1.0f,

                -1.0f, -1.0f, -1.0f, 1.0f,
                -1.0f, 1.0f, -1.0f, 1.0f,
                -1.0f, 1.0f, 1.0f, 1.0f,

                -1.0f, -1.0f, -1.0f, 1.0f,
                1.0f, -1.0f, 1.0f, 1.0f,
                1.0f, -1.0f, -1.0f, 1.0f,

                -1.0f, -1.0f, -1.0f, 1.0f,
                -1.0f, -1.0f, 1.0f, 1.0f,
                1.0f, -1.0f, 1.0f, 1.0f,

                -1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, -1.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f,

                -1.0f, 1.0f, 1.0f, 1.0f,
                -1.0f, 1.0f, -1.0f, 1.0f,
                1.0f, 1.0f, -1.0f, 1.0f,

                // korytarz

                -0.15f, -1.0f, -1.0f, 1.0f,
                -0.15f, 0.5f, -2.0f, 1.0f,
                -0.15f, -1.0f, -2.0f, 1.0f,

                -0.15f, -1.0f, -1.0f, 1.0f,
                -0.15f, 0.5f, -1.0f, 1.0f,
                -0.15f, 0.5f, -2.0f, 1.0f,

                0.15f, -1.0f, -1.0f, 1.0f,
                0.15f, 0.5f, -2.0f, 1.0f,
                0.15f, -1.0f, -2.0f, 1.0f,

                0.15f, -1.0f, -1.0f, 1.0f,
                0.15f, 0.5f, -1.0f, 1.0f,
                0.15f, 0.5f, -2.0f, 1.0f,


                0.15f, 0.5f, -2.0f, 1.0f,
                -0.15f, 0.5f, -1.0f, 1.0f,
                -0.15f, 0.5f, -2.0f, 1.0f,

                0.15f, 0.5f, -2.0f, 1.0f,
                0.15f, 0.5f, -1.0f, 1.0f,
                -0.15f, 0.5f, -1.0f, 1.0f,


                0.15f, -1.0f, -2.0f, 1.0f,
                -0.15f, -1.0f, -1.0f, 1.0f,
                -0.15f, -1.0f, -2.0f, 1.0f,

                0.15f, -1.0f, -2.0f, 1.0f,
                0.15f, -1.0f, -1.0f, 1.0f,
                -0.15f, -1.0f, -1.0f, 1.0f,
        };

        float colors[] = {
                1.0f, 0.0f, 0.0f, 1.0f,
                1.0f, 0.0f, 0.0f, 1.0f,
                1.0f, 0.0f, 0.0f, 1.0f,

                1.0f, 0.0f, 0.0f, 1.0f,
                1.0f, 0.0f, 0.0f, 1.0f,
                1.0f, 0.0f, 0.0f, 1.0f,

                1.0f, 0.0f, 0.0f, 1.0f,
                1.0f, 0.0f, 0.0f, 1.0f,
                1.0f, 0.0f, 0.0f, 1.0f,

                1.0f, 0.0f, 0.0f, 1.0f,
                1.0f, 0.0f, 0.0f, 1.0f,
                1.0f, 0.0f, 0.0f, 1.0f,

                1.0f, 0.0f, 0.0f, 1.0f,
                1.0f, 0.0f, 0.0f, 1.0f,
                1.0f, 0.0f, 0.0f, 1.0f,

                1.0f, 0.0f, 0.0f, 1.0f,
                1.0f, 0.0f, 0.0f, 1.0f,
                1.0f, 0.0f, 0.0f, 1.0f,

                0.0f, 1.0f, 0.0f, 1.0f,
                0.0f, 1.0f, 0.0f, 1.0f,
                0.0f, 1.0f, 0.0f, 1.0f,

                0.0f, 1.0f, 0.0f, 1.0f,
                0.0f, 1.0f, 0.0f, 1.0f,
                0.0f, 1.0f, 0.0f, 1.0f,

                0.0f, 0.0f, 1.0f, 1.0f,
                0.0f, 0.0f, 1.0f, 1.0f,
                0.0f, 0.0f, 1.0f, 1.0f,

                0.0f, 0.0f, 1.0f, 1.0f,
                0.0f, 0.0f, 1.0f, 1.0f,
                0.0f, 0.0f, 1.0f, 1.0f,

                0.0f, 0.0f, 1.0f, 1.0f,
                0.0f, 0.0f, 1.0f, 1.0f,
                0.0f, 0.0f, 1.0f, 1.0f,

                0.0f, 0.0f, 1.0f, 1.0f,
                0.0f, 0.0f, 1.0f, 1.0f,
                0.0f, 0.0f, 1.0f, 1.0f,

                0.0f, 0.0f, 1.0f, 1.0f,
                0.0f, 0.0f, 1.0f, 1.0f,
                0.0f, 0.0f, 1.0f, 1.0f,

                0.0f, 0.0f, 1.0f, 1.0f,
                0.0f, 0.0f, 1.0f, 1.0f,
                0.0f, 0.0f, 1.0f, 1.0f,

                1.0f, 1.0f, 0.0f, 1.0f,
                1.0f, 1.0f, 0.0f, 1.0f,
                1.0f, 1.0f, 0.0f, 1.0f,

                1.0f, 1.0f, 0.0f, 1.0f,
                1.0f, 1.0f, 0.0f, 1.0f,
                1.0f, 1.0f, 0.0f, 1.0f,

                0.0f, 1.0f, 1.0f, 1.0f,
                0.0f, 1.0f, 1.0f, 1.0f,
                0.0f, 1.0f, 1.0f, 1.0f,

                0.0f, 1.0f, 1.0f, 1.0f,
                0.0f, 1.0f, 1.0f, 1.0f,
                0.0f, 1.0f, 1.0f, 1.0f,

                1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f,

                1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f,

                1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f,

                1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f,

                1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f,

                1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f,


                1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f,

                1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f,


                1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f,

                1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f,
        };

        float normals[] = {
                0.0f, 0.0f, 1.0f, 0.0f,
                0.0f, 0.0f, 1.0f, 0.0f,
                0.0f, 0.0f, 1.0f, 0.0f,

                0.0f, 0.0f, 1.0f, 0.0f,
                0.0f, 0.0f, 1.0f, 0.0f,
                0.0f, 0.0f, 1.0f, 0.0f,

                0.0f, 0.0f, 1.0f, 0.0f,
                0.0f, 0.0f, 1.0f, 0.0f,
                0.0f, 0.0f, 1.0f, 0.0f,

                0.0f, 0.0f, 1.0f, 0.0f,
                0.0f, 0.0f, 1.0f, 0.0f,
                0.0f, 0.0f, 1.0f, 0.0f,

                0.0f, 0.0f, 1.0f, 0.0f,
                0.0f, 0.0f, 1.0f, 0.0f,
                0.0f, 0.0f, 1.0f, 0.0f,

                0.0f, 0.0f, 1.0f, 0.0f,
                0.0f, 0.0f, 1.0f, 0.0f,
                0.0f, 0.0f, 1.0f, 0.0f,

                0.0f, 0.0f, -1.0f, 0.0f,
                0.0f, 0.0f, -1.0f, 0.0f,
                0.0f, 0.0f, -1.0f, 0.0f,

                0.0f, 0.0f, -1.0f, 0.0f,
                0.0f, 0.0f, -1.0f, 0.0f,
                0.0f, 0.0f, -1.0f, 0.0f,

                -1.0f, 0.0f, 0.0f, 0.0f,
                -1.0f, 0.0f, 0.0f, 0.0f,
                -1.0f, 0.0f, 0.0f, 0.0f,

                -1.0f, 0.0f, 0.0f, 0.0f,
                -1.0f, 0.0f, 0.0f, 0.0f,
                -1.0f, 0.0f, 0.0f, 0.0f,

                -1.0f, 0.0f, 0.0f, 0.0f,
                -1.0f, 0.0f, 0.0f, 0.0f,
                -1.0f, 0.0f, 0.0f, 0.0f,

                -1.0f, 0.0f, 0.0f, 0.0f,
                -1.0f, 0.0f, 0.0f, 0.0f,
                -1.0f, 0.0f, 0.0f, 0.0f,

                -1.0f, 0.0f, 0.0f, 0.0f,
                -1.0f, 0.0f, 0.0f, 0.0f,
                -1.0f, 0.0f, 0.0f, 0.0f,

                -1.0f, 0.0f, 0.0f, 0.0f,
                -1.0f, 0.0f, 0.0f, 0.0f,
                -1.0f, 0.0f, 0.0f, 0.0f,

                1.0f, 0.0f, 0.0f, 0.0f,
                1.0f, 0.0f, 0.0f, 0.0f,
                1.0f, 0.0f, 0.0f, 0.0f,

                1.0f, 0.0f, 0.0f, 0.0f,
                1.0f, 0.0f, 0.0f, 0.0f,
                1.0f, 0.0f, 0.0f, 0.0f,

                0.0f, 1.0f, 0.0f, 0.0f,
                0.0f, 1.0f, 0.0f, 0.0f,
                0.0f, 1.0f, 0.0f, 0.0f,

                0.0f, 1.0f, 0.0f, 0.0f,
                0.0f, 1.0f, 0.0f, 0.0f,
                0.0f, 1.0f, 0.0f, 0.0f,

                0.0f, -1.0f, 0.0f, 0.0f,
                0.0f, -1.0f, 0.0f, 0.0f,
                0.0f, -1.0f, 0.0f, 0.0f,

                0.0f, -1.0f, 0.0f, 0.0f,
                0.0f, -1.0f, 0.0f, 0.0f,
                0.0f, -1.0f, 0.0f, 0.0f,


                // korytarz

                1.0f, 0.0f, 0.0f, 0.0f,
                1.0f, 0.0f, 0.0f, 0.0f,
                1.0f, 0.0f, 0.0f, 0.0f,

                1.0f, 0.0f, 0.0f, 0.0f,
                1.0f, 0.0f, 0.0f, 0.0f,
                1.0f, 0.0f, 0.0f, 0.0f,

                -1.0f, 0.0f, 0.0f, 0.0f,
                -1.0f, 0.0f, 0.0f, 0.0f,
                -1.0f, 0.0f, 0.0f, 0.0f,

                -1.0f, 0.0f, 0.0f, 0.0f,
                -1.0f, 0.0f, 0.0f, 0.0f,
                -1.0f, 0.0f, 0.0f, 0.0f,

                0.0f, -1.0f, 0.0f, 0.0f,
                0.0f, -1.0f, 0.0f, 0.0f,
                0.0f, -1.0f, 0.0f, 0.0f,

                0.0f, -1.0f, 0.0f, 0.0f,
                0.0f, -1.0f, 0.0f, 0.0f,
                0.0f, -1.0f, 0.0f, 0.0f,

                0.0f, 1.0f, 0.0f, 0.0f,
                0.0f, 1.0f, 0.0f, 0.0f,
                0.0f, 1.0f, 0.0f, 0.0f,

                0.0f, 1.0f, 0.0f, 0.0f,
                0.0f, 1.0f, 0.0f, 0.0f,
                0.0f, 1.0f, 0.0f, 0.0f,
        };

        float vertexNormals[] = {
                -0.15f, -1.0f, -1.0f, 0.0f,
                -1.0f, 1.0f, -1.0f, 0.0f,
                -1.0f, -1.0f, -1.0f, 0.0f,

                -0.15f, -1.0f, -1.0f, 0.0f,
                -0.15f, 1.0f, -1.0f, 0.0f,
                -1.0f, 1.0f, -1.0f, 0.0f,


                1.0f, -1.0f, -1.0f, 0.0f,
                0.15f, 1.0f, -1.0f, 0.0f,
                0.15f, -1.0f, -1.0f, 0.0f,

                1.0f, -1.0f, -1.0f, 0.0f,
                1.0f, 1.0f, -1.0f, 0.0f,
                0.15f, 1.0f, -1.0f, 0.0f,


                0.15f, 0.5f, -1.0f, 0.0f,
                -0.15f, 1.0f, -1.0f, 0.0f,
                -0.15f, 0.5f, -1.0f, 0.0f,

                0.15f, 0.5f, -1.0f, 0.0f,
                0.15f, 1.0f, -1.0f, 0.0f,
                -0.15f, 1.0f, -1.0f, 0.0f,


                -1.0f, -1.0f, 1.0f, 0.0f,
                1.0f, 1.0f, 1.0f, 0.0f,
                1.0f, -1.0f, 1.0f, 0.0f,

                -1.0f, -1.0f, 1.0f, 0.0f,
                -1.0f, 1.0f, 1.0f, 0.0f,
                1.0f, 1.0f, 1.0f, 0.0f,

                1.0f, -1.0f, -0.15f, 0.0f,
                1.0f, 1.0f, -1.0f, 0.0f,
                1.0f, -1.0f, -1.0f, 0.0f,

                1.0f, -1.0f, -0.15f, 0.0f,
                1.0f, 1.0f, -0.15f, 0.0f,
                1.0f, 1.0f, -1.0f, 0.0f,

                1.0f, -1.0f, 1.0f, 0.0f,
                1.0f, 1.0f, 0.15f, 0.0f,
                1.0f, -1.0f, 0.15f, 0.0f,

                1.0f, -1.0f, 1.0f, 0.0f,
                1.0f, 1.0f, 1.0f, 0.0f,
                1.0f, 1.0f, 0.15f, 0.0f,

                1.0f, 0.5f, 0.15f, 0.0f,
                1.0f, 1.0f, -0.15f, 0.0f,
                1.0f, 0.5f, -0.15f, 0.0f,

                1.0f, 0.5f, 0.15f, 0.0f,
                1.0f, 1.0f, 0.15f, 0.0f,
                1.0f, 1.0f, -0.15f, 0.0f,


                -1.0f, -1.0f, -1.0f, 0.0f,
                -1.0f, 1.0f, 1.0f, 0.0f,
                -1.0f, -1.0f, 1.0f, 0.0f,

                -1.0f, -1.0f, -1.0f, 0.0f,
                -1.0f, 1.0f, -1.0f, 0.0f,
                -1.0f, 1.0f, 1.0f, 0.0f,

                -1.0f, -1.0f, -1.0f, 0.0f,
                1.0f, -1.0f, 1.0f, 0.0f,
                1.0f, -1.0f, -1.0f, 0.0f,

                -1.0f, -1.0f, -1.0f, 0.0f,
                -1.0f, -1.0f, 1.0f, 0.0f,
                1.0f, -1.0f, 1.0f, 0.0f,

                -1.0f, 1.0f, 1.0f, 0.0f,
                1.0f, 1.0f, -1.0f, 0.0f,
                1.0f, 1.0f, 1.0f, 0.0f,

                -1.0f, 1.0f, 1.0f, 0.0f,
                -1.0f, 1.0f, -1.0f, 0.0f,
                1.0f, 1.0f, -1.0f, 0.0f,

                // korytarz

                -0.15f, -1.0f, -1.0f, 0.0f,
                -0.15f, 0.5f, -2.0f, 0.0f,
                -0.15f, -1.0f, -2.0f, 0.0f,

                -0.15f, -1.0f, -1.0f, 0.0f,
                -0.15f, 0.5f, -1.0f, 0.0f,
                -0.15f, 0.5f, -2.0f, 0.0f,

                0.15f, -1.0f, -1.0f, 0.0f,
                0.15f, 0.5f, -2.0f, 0.0f,
                0.15f, -1.0f, -2.0f, 0.0f,

                0.15f, -1.0f, -1.0f, 0.0f,
                0.15f, 0.5f, -1.0f, 0.0f,
                0.15f, 0.5f, -2.0f, 0.0f,


                0.15f, 0.5f, -2.0f, 0.0f,
                -0.15f, 0.5f, -1.0f, 0.0f,
                -0.15f, 0.5f, -2.0f, 0.0f,

                0.15f, 0.5f, -2.0f, 0.0f,
                0.15f, 0.5f, -1.0f, 0.0f,
                -0.15f, 0.5f, -1.0f, 0.0f,


                0.15f, -1.0f, -2.0f, 0.0f,
                -0.15f, -1.0f, -1.0f, 0.0f,
                -0.15f, -1.0f, -2.0f, 0.0f,

                0.15f, -1.0f, -2.0f, 0.0f,
                0.15f, -1.0f, -1.0f, 0.0f,
                -0.15f, -1.0f, -1.0f, 0.0f,
        };

        float texCoords[] = {
                0.15f, -1.0f,  -1.0f, 1.0f,  -1.0f, -1.0f,
                -0.15f, -1.0f, -0.15f, 1.0f, -1.0f, 1.0f,

                1.0f, -1.0f, 0.15f, 1.0f, 0.15f, -1.0f,
                1.0f, -1.0f,1.0f, 1.0f, 0.15f, 1.0f,

                0.15f, 0.5f, -0.15f, 1.0f, -0.15f, 0.5f,
                0.15f, 0.5f, 0.15f, 1.0f, -0.15f, 1.0f,

                1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f,

                0.15f, -1.0f,  -1.0f, 1.0f,  -1.0f, -1.0f,
                -0.15f, -1.0f, -0.15f, 1.0f, -1.0f, 1.0f,

                1.0f, -1.0f, 0.15f, 1.0f, 0.15f, -1.0f,
                1.0f, -1.0f,1.0f, 1.0f, 0.15f, 1.0f,

                0.15f, 0.5f, -0.15f, 1.0f, -0.15f, 0.5f,
                0.15f, 0.5f, 0.15f, 1.0f, -0.15f, 1.0f,

                1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f,

                1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f,

                1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f,


                //korytarz

                1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f,

                1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f,

                1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f,

                1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f,

                1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f,

                1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f,

                1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f,

                1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f,

        };
    }
}