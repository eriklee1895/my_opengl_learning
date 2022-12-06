// 演示SDL+GLEW创建window
// https://subscription.packtpub.com/book/game-development/9781789340365/1/ch01lvl1sec14/setting-up-opengl-using-sdl-on-a-mac
// https://github.com/PacktPublishing/Learn-OpenGL/blob/master/Chapter01/SDL/Mac/SDLOpenGL/main.cpp

#include <iostream>
#include <SDL2/SDL.h>

#define GLEW_STATIC
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

const GLint WIDTH = 800, HEIGHT = 600;

int main( int argc, char *argv[] )
{
    SDL_Init( SDL_INIT_EVERYTHING );

    // SDL有3种OpenGL Profile:
    // ES - which is embedded systems, for stuff like mobile devices
    // core profile - which is for modern OpenGL
    // compatibility profile - which allows you to use an older version of OpenGL and ensures maximum compatibility.
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3 );
    SDL_GL_SetAttribute( SDL_GL_STENCIL_SIZE, 8 );

    SDL_Window *window = SDL_CreateWindow( "OpenGL", 0, 0, WIDTH, HEIGHT, SDL_WINDOW_OPENGL );

    SDL_GLContext context = SDL_GL_CreateContext( window );


    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;
    // Initialize GLEW to setup the OpenGL Function pointers
    if ( GLEW_OK != glewInit( ) )
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return EXIT_FAILURE;
    }

    // Define the viewport dimensions
    glViewport( 0, 0, WIDTH, HEIGHT );

    SDL_Event windowEvent;

    while ( true )
    {
        if ( SDL_PollEvent( &windowEvent ) )
        {
            if ( windowEvent.type == SDL_QUIT ) break;
        }

        // Clear the colorbuffer
        glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
        glClear( GL_COLOR_BUFFER_BIT );

        // draw OpenGL

        SDL_GL_SwapWindow( window );
    }

    SDL_GL_DeleteContext( context );
    SDL_DestroyWindow( window );
    SDL_Quit( );

    return EXIT_SUCCESS;
}