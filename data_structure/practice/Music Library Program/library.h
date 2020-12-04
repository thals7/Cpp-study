#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct song Song;
typedef struct snode SNode;
typedef struct artist Artist;

struct song
{
    Artist *artist;
    char *title;
    char *path;
    int index;
};

struct snode // 양방향 연결리스트
{
    SNode *next, *prev; // 다음곡과 이전곡을 연결
    Song *song;
};

struct artist
{
    char *name;
    Artist *next; // 이름의 첫글자가 같은 가수들을 단방향 연결리스트로 연결
    SNode *head, *tail; // 가수가 부른 노래들을 연결해주는 snode 포인터
};

void initialize();
void add_song(char *artist, char *title, char *path);
void status();
void load(FILE *fp);
void search_song(char *artist, char *title);
void search_song(char *artist);
void play(int index);
void remove(int index);
void save(FILE *fp);

#endif