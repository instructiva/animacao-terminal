#include <ncurses.h>
#include <unistd.h>

#define DELAY 30000

int main() {
    int x = 0, y = 0;
    int max_x = 0, max_y = 0;
    int next_x = 0;
    int direction = 1;

    // Inicializa a tela do terminal
    initscr();

    // Esconde o cursor do terminal
    curs_set(FALSE);

    // Habilita o uso de teclas especiais (F1, F2, setas, etc.)
    keypad(stdscr, TRUE);

    // Desabilita o bloqueio do input do terminal
    nodelay(stdscr, TRUE);

    // Captura as dimensões da tela
    getmaxyx(stdscr, max_y, max_x);

    while (1) {
        // Limpa a tela
        clear();

        // Desenha a bola na posição atual
        mvprintw(y, x, "o");

        // Atualiza a tela
        refresh();

        // Espera um curto período de tempo
        usleep(DELAY);

        // Captura o input do teclado
        int ch = getch();

        // Se a tecla q for pressionada, encerra o programa
        if (ch == 'q') {
            break;
        }

        // Move a bola para a próxima posição
        next_x = x + direction;

        // Inverte a direção caso a bola atinja os limites do terminal
        if (next_x >= max_x || next_x < 0) {
            direction *= -1;
        } else {
            x += direction;
        }

        // Aumenta ou diminui a coordenada y para simular o quique da bola
        if (y < max_y - 1) {
            y++;
        } else {
            y = 0;
        }
    }

    // Restaura as configurações do terminal
    endwin();

    return 0;
}
