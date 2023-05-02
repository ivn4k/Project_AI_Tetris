#include <SFML/Graphics.hpp>
#include <conio.h>
#include <time.h>

using namespace sf;

const int block_size = 30;
const int field_width = 10;
const int field_height = 20;

int field[field_width][field_height] = { 0 };

Color myColor2(0, 255, 0, 128);

struct Point
{
    int x, y;
} a[4], b[4];

void draw_block(int x, int y, Color color, RenderWindow& window)
{
    RectangleShape block(Vector2f(block_size - 1, block_size - 1));
    block.setFillColor(color);
    block.setPosition(x * block_size + 0.5, y * block_size + 0.5);
    window.draw(block);
}

int main()
{
    RenderWindow window(VideoMode(field_width * block_size, field_height * block_size), "Tetris");
    //RenderWindow window(VideoMode(320, 480), "Tetris");

    int i = 0;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::White);



        for (int i = 0; i < field_width; i++)
            for (int j = 0; j < field_height; j++)
            {
                if (field[i][j] == 0)
                    continue;
                draw_block(i, j, Color::Red, window);
            }

        for (int i = 0; i <= field_height; i++)
        {
            Vertex line[] =
            {
                Vertex(Vector2f(0, i * block_size)),
                Vertex(Vector2f(field_width * block_size, i * block_size))
            };
            line[0].color = myColor2;
            line[1].color = myColor2;
            window.draw(line, 2, Lines);
        }

        for (int j = 0; j <= field_width; j++)
        {
            Vertex line[] =
            {
                Vertex(Vector2f(j * block_size, 0)),
                Vertex(Vector2f(j * block_size, field_height * block_size))
            };
            line[0].color = myColor2;
            line[1].color = myColor2;
            window.draw(line, 2, Lines);
        }

        field[0][i] = 1;
        i++;

        window.display();
        //Sleep(300);
    }

    return 0;
}