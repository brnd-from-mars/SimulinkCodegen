/*
 * project: Simulink Codegen
 * author: Brendan Berg
 * date: 2023-06-19
 *
 * Copyright: (c) Brendan Berg 2023
 */

#include <util/delay.h>
#include <stdbool.h>

#include "controller.h"
#include "target_system.h"

int main(void)
{
    double x;
    double e;
    double u;
    double y = 0.0;

    while (true)
    {
        x = 1.0;
        e = x - y;
        u = controller(e);
        y = target_system(u);

        _delay_ms(10);
    }

    return 0;
}
