if (k2[i][j] == " ")
{
    if (i < 1 && j < 1 && (k2[i][j + 1] == "0" || k2[i + 1][j] == "0" || k2[i + 1][j + 1] == "0"))
    {
        k2[i][j] = k[i][j];
        count++;
    }
    if (i < 1 && j > 8 && (k2[i][j - 1] == "0" || k2[i + 1][j - 1] == "0" || k2[i + 1][j] == "0"))
    {
        k2[i][j] = k[i][j];
        count++;
    }
    if (i < 1 && j > 1 && j < 9 && (k2[i][j - 1] == "0" || k2[i][j + 1] == "0" || k2[i + 1][j - 1] == "0" || k2[i + 1][j] == "0" || k2[i + 1][j + 1] == "0"))
    {
        k2[i][j] = k[i][j];
        count++;
    }
    if (i > 8 && j < 1 && (k2[i - 1][j] == "0" || k2[i - 1][j + 1] == "0" || k2[i][j + 1] == "0"))
    {
        k2[i][j] = k[i][j];
        count++;
    }
    if (i > 8 && j > 8 && (k2[i - 1][j - 1] == "0" || k2[i - 1][j] == "0" || k2[i][j - 1] == "0"))
    {
        k2[i][j] = k[i][j];
        count++;
    }
    if (i > 8 && j > 1 && j < 9 && (k2[i - 1][j - 1] == "0" || k2[i - 1][j] == "0" || k2[i - 1][j + 1] == "0" || k2[i][j - 1] == "0" || k2[i][j + 1] == "0"))
    {
        k2[i][j] = k[i][j];
        count++;
    }
    if (j < 1 && i > 1 && i < 9 && (k2[i - 1][j] == "0" || k2[i - 1][j + 1] == "0" || k2[i][j + 1] == "0" || k2[i + 1][j] == "0" || k2[i + 1][j + 1] == "0"))
    {
        k2[i][j] = k[i][j];
        count++;
    }
    if (j > 8 && i > 1 && i < 9 && (k2[i - 1][j - 1] == "0" || k2[i - 1][j] == "0" || k2[i][j - 1] == "0" || k2[i + 1][j - 1] == "0" || k2[i + 1][j - 1] == "0" || k2[i + 1][j] == "0"))
    {
        k2[i][j] = k[i][j];
        count++;
    }
    if (i > 1 && i < 9 && j > 1 && j < 9 && (k2[i - 1][j - 1] == "0" || k2[i - 1][j] == "0" || k2[i - 1][j + 1] == "0" || k2[i][j - 1] == "0" || k2[i][j + 1] == "0" || k2[i + 1][j - 1] == "0" || k2[i + 1][j] == "0" || k2[i + 1][j + 1] == "0"))
    {
        k2[i][j] = k[i][j];
        count++;
    }
}