int fill(int x, int y, int banyakLangkah)
{
	if(x == tujuanX && y == tujuanY){
		if(banyakLangkah < minLangkah)
			minLangkah = banyakLangkah;
	}
    else if (x >= 1 && x <= 8 && y >= 1 && y <= 8)
    {
        fill(x + 2, y + 1, banyakLangkah + 1);
        fill(x + 2, y - 1, banyakLangkah + 1);
        fill(x - 2, y + 1, banyakLangkah + 1);
        fill(x - 2, y - 1, banyakLangkah + 1);
        fill(x + 1, y + 2, banyakLangkah + 1);
        fill(x + 1, y - 2, banyakLangkah + 1);
        fill(x - 1, y + 2, banyakLangkah + 1);
        fill(x - 1, y - 2, banyakLangkah + 1);
    }

	return 0;
}