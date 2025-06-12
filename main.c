#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int provjeri_pobjedu_meta_polje(int polje[11][11], int meta_x, int meta_y)
{
    int bx = meta_x * 4;
    int by = meta_y * 4;

    for (int igrac = 1; igrac <= 2; igrac++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (polje[by + i][bx + 0] == igrac && polje[by + i][bx + 1] == igrac && polje[by + i][bx + 2] == igrac)
                return igrac;
            if (polje[by + 0][bx + i] == igrac && polje[by + 1][bx + i] == igrac && polje[by + 2][bx + i] == igrac)
                return igrac;
        }
        if (polje[by + 0][bx + 0] == igrac && polje[by + 1][bx + 1] == igrac && polje[by + 2][bx + 2] == igrac)
            return igrac;
        if (polje[by + 0][bx + 2] == igrac && polje[by + 1][bx + 1] == igrac && polje[by + 2][bx + 0] == igrac)
            return igrac;
    }

    return 0;
}

void oznaci_pobjedu(int polje[11][11], int meta_x, int meta_y, int igrac)
{
    int bx = meta_x * 4;
    int by = meta_y * 4;
    int oznaka = (igrac == 1) ? 9 : 8;

    for (int i = 0; i < 3; i++)
    {
        if (polje[by + i][bx + 0] == igrac && polje[by + i][bx + 1] == igrac && polje[by + i][bx + 2] == igrac)
            for (int j = 0; j < 3; j++)
                polje[by + i][bx + j] = oznaka;

        if (polje[by + 0][bx + i] == igrac && polje[by + 1][bx + i] == igrac && polje[by + 2][bx + i] == igrac)
            for (int j = 0; j < 3; j++)
                polje[by + j][bx + i] = oznaka;
    }

    if (polje[by + 0][bx + 0] == igrac && polje[by + 1][bx + 1] == igrac && polje[by + 2][bx + 2] == igrac)
        for (int j = 0; j < 3; j++)
            polje[by + j][bx + j] = oznaka;

    if (polje[by + 0][bx + 2] == igrac && polje[by + 1][bx + 1] == igrac && polje[by + 2][bx + 0] == igrac)
        for (int j = 0; j < 3; j++)
            polje[by + j][bx + 2 - j] = oznaka;
}

int provjeri_ukupnu_pobjedu(int meta[3][3])
{
    for (int igrac = 1; igrac <= 2; igrac++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (meta[i][0] == igrac && meta[i][1] == igrac && meta[i][2] == igrac)
                return igrac;
            if (meta[0][i] == igrac && meta[1][i] == igrac && meta[2][i] == igrac)
                return igrac;
        }
        if (meta[0][0] == igrac && meta[1][1] == igrac && meta[2][2] == igrac)
            return igrac;
        if (meta[0][2] == igrac && meta[1][1] == igrac && meta[2][0] == igrac)
            return igrac;
    }
    return 0;
}

int provjeri_nerijeseno_meta_polje(int polje[11][11], int meta_x, int meta_y)
{
    int bx = meta_x * 4;
    int by = meta_y * 4;
    for (int j = 0; j < 3; j++)
        for (int i = 0; i < 3; i++)
            if (polje[by + j][bx + i] == 0)
                return 0; // ima praznih
    return 1;             // sve je popunjeno
}

int main()
{
    int igraZapocela = 0;
    char ime1[50], ime2[50];
    char unos[100];

    printf("\t\t\tStrateški križić kružić\n");
    printf("\n\tPravila\n\n");
    printf("1. Ima dva igrač.\n");
    printf("2. Prvo se igra u srednjem polju.\n");
    printf("3. Igrači mjenjaju poteze prvo jedan pa drugi.\n");
    printf("4. Igraj samo na bijelim poljima.\n");
    printf("5. Prati koordinate, prvo slovo pa broj (treba biti razmak između njih), npr. I 8\n");
    printf("6. Poslije svakog poteza igra se u polju prema kojem je zadnji potez napravljen.\n");
    printf("7. Ne smiješ stavljati na crna polja ili polja koja već imaju ✖  ili ⭕!\n");
    printf("8. Način na koji pobijeđuješ je dobijajući 3 mala polja u redu, stupci ili dijagonali.\n");
    printf("9. Način na koji dobiješ ta mala polja je to da spojiš 3 isto kao i u normalnom križić kružiću.\n");
    printf("10. Kad spojis 3 ✖  ili ⭕ u jednom meta-polju pretvoriti će se u kvadratiće 🟪 -za ✖  i 🟥 -za ⭕.\n");

    printf("   A  B  C    D  E  F    G  H  I\n");
    printf(" 1⬜ ⬜ ⬜   ⬜ ⬜ ⬜   ⬜ ⬜ ⬜\n");
    printf(" 2⬜ ⬜ ⬜   ⬜ ⬜ ⬜   ⬜ ⬜ ⬜\n");
    printf(" 3⬜ ⬜ ⬜   ⬜ ⬜ ⬜   ⬜ ⬜ ⬜\n");
    printf("                                    \n");
    printf(" 4⬜ ⬜ ⬜   ⬜ ⬜ ⬜   ⬜ ⬜ ⬜\n");
    printf(" 5⬜ ⬜ ⬜   ⬜ ⬜ ⬜   ⬜ ⬜ ⬜\n");
    printf(" 6⬜ ⬜ ⬜   ⬜ ⬜ ⬜   ⬜ ⬜ ⬜\n");
    printf("                                    \n");
    printf(" 7⬜ ⬜ ⬜   ⬜ ⬜ ⬜   ⬜ ⬜ ⬜\n");
    printf(" 8⬜ ⬜ ⬜   ⬜ ⬜ ⬜   ⬜ ⬜ ⬜\n");
    printf(" 9⬜ ⬜ ⬜   ⬜ ⬜ ⬜   ⬜ ⬜ ⬜\n");

    printf("igrac 1 upisi svoje ime: ");
    fgets(ime1, sizeof(ime1), stdin);
    printf("igrac 2 upisi svoje ime: ");
    fgets(ime2, sizeof(ime2), stdin);

    printf("\nUnesi 1 za početak igre: ");
    scanf("%d", &igraZapocela);
    getchar();

    if (igraZapocela != 1)
    {
        printf("Igra nije započela.\n");
        return 0;
    }

    int polje[11][11] = {0};
    int meta[3][3] = {0};
    int meta_ploca_x = 1, meta_ploca_y = 1;
    int igrac = 1;
    int ukupni_pobjednik = 0;

    while (1)
    {
        system("cls");

        // unosi slova iznad ploče
        printf("   ");
        for (int x = 0, slovo = 'A'; x < 11; x++)
        {
            if (x % 4 == 3)
                printf("   ");
            else
                printf(" %c ", slovo++);
        }
        printf("\n");

        int prikazani_broj = 1;
        for (int y = 0; y < 11; y++)
        {
            // unosi brojeve s lijeve strane ploče
            if (y % 4 == 3)
                printf("   ");
            else
                printf("%2d ", prikazani_broj++);

            for (int x = 0; x < 11; x++)
            {
                if (x % 4 == 3 || y % 4 == 3)
                {
                    printf("   ");
                    continue;
                }

                if (polje[y][x] == 1)
                    printf("✖  ");
                else if (polje[y][x] == 2)
                    printf("⭕ ");
                else if (polje[y][x] == 9)
                    printf("🟪 ");
                else if (polje[y][x] == 8)
                    printf("🟥 ");
                else
                {
                    int mx = x / 4;
                    int my = y / 4;
                    int dozvoljeno = (meta_ploca_x == -1 || (mx == meta_ploca_x && my == meta_ploca_y));
                    printf(dozvoljeno ? "⬜ " : "⬛ ");
                }
            }
            printf("\n");
        }

        if (ukupni_pobjednik)
        {
            if (ukupni_pobjednik == 1)
            {
                printf("\n %s 🎉 JE POBIJEDIO IGRU! (neš ti zadatka) 🎉\n", ime1);
            }
            else
            {
                printf("\n %s 🎉 JE POBIJEDIO IGRU! (neš ti zadatka) 🎉\n", ime2);
            }
            break;
        }

        // Provjera neriješenog
        int nerijeseno = 1;
        for (int y = 0; y < 3 && nerijeseno; y++)
            for (int x = 0; x < 3 && nerijeseno; x++)
                if (meta[y][x] == 0)
                    nerijeseno = 0;

        if (!ukupni_pobjednik && nerijeseno)
        {
            printf("\n IGRA JE NERJEŠENA! \n");
            break;
        }

        if (igrac == 1)
        {
            printf("\n%sunesi koordinate (slovo broj):", ime1);
        }
        else
        {
            printf("\n%sunesi koordinate (slovo broj):", ime2);
        }

        fgets(unos, sizeof(unos), stdin);
        char sx;
        int broj;
        if (sscanf(unos, " %c %d", &sx, &broj) != 2)
        {
            printf("Neispravan unos. Pokušaj ponovno.\n");
            printf("Pritisni Enter za nastavak...\n");
            fgets(unos, sizeof(unos), stdin);
            continue;
        }

        int logicko_x = sx - 'A';
        int logicko_y = broj - 1;

        if (logicko_x < 0 || logicko_x >= 9 || logicko_y < 0 || logicko_y >= 9)
        {
            printf("Koordinate izvan raspona.\n");
            printf("Pritisni Enter za nastavak...\n");
            fgets(unos, sizeof(unos), stdin);
            continue;
        }

        int x = logicko_x + logicko_x / 3;
        int y = logicko_y + logicko_y / 3;

        if (x % 4 == 3 || y % 4 == 3 || polje[y][x] != 0)
        {
            printf("Polje je već zauzeto.\n");
            printf("Pritisni Enter za nastavak...\n");
            fgets(unos, sizeof(unos), stdin);
            continue;
        }

        int meta_x = x / 4;
        int meta_y = y / 4;

        if (meta_ploca_x != -1 && (meta_x != meta_ploca_x || meta_y != meta_ploca_y))
        {
            printf("Ne možeš igrati u ovom meta-polju.\n");
            printf("Pritisni Enter za nastavak...\n");
            fgets(unos, sizeof(unos), stdin);
            continue;
        }
        polje[y][x] = igrac;

        int pobjednik = provjeri_pobjedu_meta_polje(polje, meta_x, meta_y);
        if (pobjednik && meta[meta_y][meta_x] == 0)
        {
            oznaci_pobjedu(polje, meta_x, meta_y, pobjednik);
            meta[meta_y][meta_x] = pobjednik;
            ukupni_pobjednik = provjeri_ukupnu_pobjedu(meta);
        }
        else if (!pobjednik && meta[meta_y][meta_x] == 0 && provjeri_nerijeseno_meta_polje(polje, meta_x, meta_y))
        {
            meta[meta_y][meta_x] = 3; // neriješeno meta-polje
        }

        int lokal_x = x % 4;
        int lokal_y = y % 4;
        int novi_meta_x = lokal_x;
        int novi_meta_y = lokal_y;

        if (novi_meta_x >= 3 || novi_meta_y >= 3)
        {
            meta_ploca_x = -1;
            meta_ploca_y = -1;
        }
        else
        {
            int prazno = 0;
            for (int j = 0; j < 3 && !prazno; j++)
                for (int i = 0; i < 3 && !prazno; i++)
                {
                    int tx = novi_meta_x * 4 + i;
                    int ty = novi_meta_y * 4 + j;
                    if (polje[ty][tx] == 0)
                        prazno = 1;
                }

            if (prazno)
            {
                meta_ploca_x = novi_meta_x;
                meta_ploca_y = novi_meta_y;
            }
            else
            {
                meta_ploca_x = -1;
                meta_ploca_y = -1;
            }
        }

        igrac = 3 - igrac;
    }

    return 0;
}