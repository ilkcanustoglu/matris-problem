/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matris-problem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iustoglu <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:03:04 by iustoglu          #+#    #+#             */
/*   Updated: 2022/04/16 18:03:06 by iustoglu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

int asal_sayi(int sayi)
{
    int bolum=3;
    
    if(sayi == 2)   return 0;
    if(sayi == 1)   return 1;
    if(sayi%2 == 0) return 2;
    
    for(bolum=3; bolum < sqrt(sayi)+1; bolum+=2)
        if((sayi % bolum)== 0)
            return bolum;
    
    return 0;
}

int main ()

{
    int matris [15][15] = {
        {215},
        {193,124},
        {117,237,442},
        {218,935,347,235},
        {320,804,522,417,345},
        {229,601,723,835,133,124},
        {248,202,277,433,207,263,257},
        {359,464,504,528,516,716,871,182},
        {461,441,426,656,863,560,380,171,923},
        {381,348,573,533,447,632,387,176,975,449},
        {223,711,445,645,245,543,931,532,937,541,444},
        {330,131,333,928,377,733,017,778,839,168,197,197},
        {131,171,522,137,217,224,291,413,528,520,227,229,928},
        {223,626,034,683,839,053,627,310,713,999,629,817,410,121},
        {924,622,911,233,325,139,721,218,253,223,107,233,230,124,233}
        
    };
    
    int i = 0;
    int j = 0;
    int left = 0;
    int right = 0;
    int sum = 0;
    
    
    while (i < 15)
    {
        if (j == 0)
        {
            left = matris[i][j];
        }
        
        else
        {
            left = matris [i][j - 1];
        }
        
        right = matris [i][j + 1];
            
        if (left > right && asal_sayi(left) != 0)
        {
            sum += left;
            if (j != 0)
                j--;
        }
        if (left == right)
        {
            sum += left;
            if (j != 0)
                j--;
        }
        if (right > left && asal_sayi(right) != 0)
        {
            sum += right;
            j++;
        }
        
        if (left > right && asal_sayi(left) == 0)
        {
            sum += right;
            j++;
        }
        if (right > left && asal_sayi(right) == 0)
        {
            sum += left;
            if (j != 0)
                j--;
        }
        
    i++;
}
    printf("%d\n",sum);
}
