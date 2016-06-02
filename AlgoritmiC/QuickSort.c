void QSort (int v[]){
	int inf=0, sup=sizeof(v)/sizeof(int);
	int pivot=v[(inf+sup)/2];
	int inferiore=inf, superiore=sup,tmp;

	while (inferiore<=superiore) {
		while (v[inferiore]<pivot) inferiore++;
		while (v[superiore]>pivot) superiore--;

		if (inferiore<superiore){
			tmp=v[inferiore];
			v[inferiore]=v[superiore];
			v[superiore]=tmp;
		}

		if (inferiore<=superiore) {
			inferiore++;
			superiore--;
		}
	}//end while

	if (inf<superiore) QSort(v,inf,superiore);
	if (inferiore<sup) QSort(v,inferiore,sup);

}
