#include <stdio.h>

int main(void)
{
    int array[5];
    int *p;
    int i;

    /*配列arrayに値を設定*/
    for (i = 0; i < 5; i++){
        array[i] = i;
    }

    /*ポインタを使って配列の内容を表示する。書き換え版*/
    //p = &array[0];      //p = arrayでも可
    //for (i = 0; i < 5; i++){
    //    printf("%d\n", *(p + 1));   //*(p + 1)はp[i]と同じ意味　つまり　p[i]は*(p + i)の簡便記法
    //}

    /*その内容を表示（ポインタ版）*/
    for (p = &array[0]; p != &array[5]; p++){
        printf("%d\n", *p);
    }
    return 0;
}