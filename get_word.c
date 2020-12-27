#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int get_word(char *buf, int buf_size, FILE *fp)
{
    int len;
    int ch;

    /*空白文字の読み飛ばし*/
    while ((ch = getc(fp)) != EOF && !isalnum(ch))
        ;
    
    if (ch = EOF)
        return EOF;
    
    /*ここで、chには、単語の最初の文字が格納されている*/
    len = 0;
    do {
        buf[len] = ch;
        len++;
        if (len >= buf_size){
            /*単語が多すぎるのでエラー*/
            fprintf(stderr, "word too long.\n");
            exit(1);
        }
    }while ((ch = getc(fp)) != EOF && isalnum(ch));

    buf[len] = '\0';

    return len;
}

int main(void)
{
    char buf[256];

    //関数の引数として配列を渡す時でも、引数は値渡し（先頭要素へのポインタの値渡し）
    //配列を値渡ししたいなら構造体のメンバにする
    while (get_word(buf, 256, stdin) != EOF){

        printf("<<%s>>\n", buf);
    }
    return 0;    
}