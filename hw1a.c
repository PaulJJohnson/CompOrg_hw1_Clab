/*
 * CS:2630
 * Author: Paul Johnson
 * hawkid: pjohnson16
 */

#include <stdio.h>
#include "hw1a.h"

/* Return the max integer of the cnt values in array */
int maxNumber(int array[], int cnt)
{
	if (cnt <= 0)
	{
		return 0;
	}

	int maxNumber = array[0];

	/*
	 *  Loops through the array and gets the greatest number by
	 *  comparing the current index of the array and the maxNumber
	 *  value.
	 */
	for (int i = 1; i < cnt; i++)
	{
		if (maxNumber < array[i])
		{
			maxNumber = array[i];
		}
	}

	return maxNumber;
}

/* Return the min integer of the cnt values in array */
int minNumber(int array[], int cnt)
{
	if (cnt <= 0)
	{
		return 0;
	}

	int minNumber = array[0];

	for (int i = 1; i < cnt; i++)
	{
		if (minNumber > array[i])
		{
			minNumber = array[i];
		}
	}

	return minNumber;
}

/* Return the sum of the cnt values in array */
int sum(int array[], int cnt)
{
	if (cnt <= 0)
	{
		return 0;
	}

	int total = 0;

	for (int i = 0; i < cnt; i++)
	{
		total += array[i];
	}

	return total;
}

/*
 * Sort the values of array in place. The length of array is cnt.
 * Upon return, array will contain the original values sorted in
 * increasing order (i.e., smallest number first). Using the
 * BubbleSort algorithm.
 *
 * I did Google the algorithm.
 */
void sortIncreasingOrder(int array[], int cnt)
{
	// Loop through each index.
	for (int i = 0; i < cnt - 1; i++)
	{
		/*
		 * Loops through each index from a given index
		 * and onward. Never returns to an index lower
		 * than the given j index.
		 */
		for (int j = 0; j < cnt - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/*
				 * The swap method broken out.
				 * I would have prefered to implement
				 * this in another function called sort.
				 */
				int value = array[j];
				array[j] = array[j + 1];
				array[j + 1] = value;
			}
		}
	}
}

/*
 * Sort the values of array in place. The length of array is cnt.
 * Upon return, array will contain the original values sorted in
 * decreasing order (i.e., largest number first). Using the
 * BubbleSort algorithm.
 */
void sortDecreasingOrder(int array[], int cnt)
{
	// Loop through each index.
	for (int i = 0; i < cnt - 1; i++)
	{
		/*
		 * Loops through each index from a given index
		 * and onward. Never returns to an index lower
		 * than the given j index.
		 */
		for (int j = 0; j < cnt - i - 1; j++)
		{
			if (array[j] < array[j + 1])
			{
				/*
				 * The swap method broken out.
				 * I would have prefered to implement
				 * this in another function called sort.
				 */
				int value = array[j];
				array[j] = array[j + 1];
				array[j + 1] = value;
			}
		}
	}
}

/*
 * Returns the median of the numbers in an array.
 * This will round by default as the function gets
 * the mean of two medians if there are an even
 * number of elements in the array.
 */
int medianNumber(int array[], int cnt)
{
	int medianIndex = cnt / 2;

	/*
	 * Median formula is [Median = (n+1)/2]
	 * The original forumal above does not see n as the count so
	 * we won't be adding the 1 to cnt.
	 *
	 * We also need an ordered list of integers for this to work.
	 */

	// Use the sort method from above.
	sortIncreasingOrder(array, cnt);

	/*
	 * Need to know if it is even to know if one
	 * or two medians exist.
	 */
	if (cnt % 2 == 0)
	{
		// Return the average of the two medians
		int median1 = array[medianIndex - 1];
		int median2 = array[medianIndex];

		return (median1 + median2) / 2;
	}
	else
	{
		return array[medianIndex];
	}
}
