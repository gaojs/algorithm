#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>


typedef struct {
    int id, time;
} node_t;

#define MAX_COUNT 2001
typedef struct {
    node_t d[MAX_COUNT];
    int count;
} LogSystem;

LogSystem* LogSystemCreate()
{
    static LogSystem s_LogSys;
    memset(&s_LogSys, 0, sizeof(s_LogSys));
    return &s_LogSys;
}

void LogSystemAdd(LogSystem* ls, int id, int time)
{
    if (ls == NULL || id <= 0 || time <= 0) {
        return;
    }
    ls->d[ls->count].id = id;
    ls->d[ls->count].time = time;
    ls->count++;
}

int LogSystemDelete(LogSystem* ls, int id)
{
    if (ls == NULL || id <= 0) {
        return -1;
    }
    for (int i = 0; i < ls->count; i++) {
        if (ls->d[i].id == id) {
            if (ls->count - i - 1 > 0) {
                memmove(&ls->d[i], &ls->d[i + 1], sizeof(node_t) *(ls->count - i - 1));
            }
            ls->count--;
            return 0;
        }
    }
    return -1;
}

int LogSystemQuery(LogSystem* ls, int start, int end)
{
    if (ls == NULL || start <= 0 || end <= 0) {
        return 0;
    }
    int count = 0;
    for (int i = 0; i < ls->count; i++) {
        if (ls->d[i].time >= start && ls->d[i].time <= end) {
            count++;
        }
    }
    return count;
}

void LogSystemFree(LogSystem* ls)
{
}

int main()
{
    LogSystem*ls = LogSystemCreate();
    LogSystemAdd(ls, 1, 5);
    LogSystemAdd(ls, 2, 5);
    LogSystemAdd(ls, 3, 6);
    int r = LogSystemQuery(ls, 5, 6);
    printf("q=%d\n", r);
    r = LogSystemDelete(ls, 2);
    printf("d=%d\n", r);
    r = LogSystemDelete(ls, 4);
    printf("d=%d\n", r);
    r = LogSystemQuery(ls, 5, 6);
    printf("q=%d\n", r);
    LogSystemFree(ls);
    return 0;
}


