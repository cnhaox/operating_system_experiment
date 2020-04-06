#include "command.h"
unsigned char ramFDD144[1474560];
unsigned char cur = ROOT;
struct ActiveFile active_list[MAX_ACTIVE_FILE];
struct OpenFile open_list[MAX_OPEN_FILE];
char command[10];
char parameter[100];
int main()
{
    init_ramFDD144(ramFDD144, "../fdd144.img");
    struct RootEntry *space = (struct RootEntry *)(ramFDD144 + 9728);
    unsigned char *data = (unsigned char *)(ramFDD144 + 16896);
    while (1)
    {
        print_path(cur, space);
        putchar('>');
        read_command(command, parameter);
        if (is_command(command, "EXIT"))
        {
            break;
        }
        if (is_command(command, "CLS"))
        {
            system("cls");
            continue;
        }
        //puts(command);
        //puts(parameter);
        execute_command(command, parameter, &cur, ramFDD144, ramFDD144 + 512, ramFDD144 + 5120, space, data, active_list, open_list);
    }
}