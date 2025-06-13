<a href="https://github.com/MAZHARMIK"><img style="position: absolute; top: 0; left: 0; border: 0;" src="https://github.blog/wp-content/uploads/2008/12/forkme_left_orange_ff7600.png?resize=149%2C149" alt="Fork me on GitHub" data-canonical-src="https://s3.amazonaws.com/github/ribbons/forkme_left_red_aa0000.png"></a>
<img src="https://1.bp.blogspot.com/-71RCmZ89ljY/Vi_VOMruhGI/AAAAAAAAAnI/nVf2cJj8tac/s1600/BitManipulation.png" width="600" height="250">


# Bit_Magic : :triangular_flag_on_post:
Remember Few Things : 
```
- (1 << n) = 2^n . Generalised : n << x = n * 2^x

- Similarly, n >> x = n / 2^x

- if ( (x & (1 << i)) == 0 ) , then ith bit of x is unset (i.e. 0)
  This will help you find subset using bit manipulation. 
  
- If we subtract a power of 2 number by 1 then all unset bits after the
  only set bit become set, and the set bit becomes unset.
  For example for 4 (100) and 16(10000), we get the following after subtracting 1 
      3 –> 011 
      15 –> 01111

   So, if( (n&(n-1)) == 0) - n is even
```
See <a href= "https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Subsets.cpp">Subsets</a> And <a href= "https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Calculate%207n%5C8%20without%20using%20division%20and%20multiplication.cpp">This</a> for Questions based on above.


<h1>Questions</h1>
<table id = "example" class="SectionTable display" >
		<thead>
      <th>Problem Name</th>
		</thead>
		<tbody>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Single%20Number%20III.cpp">Single Number III (Leetcode-260)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Single%20Number%20II.cpp">Single Number II (Leetcode-137)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Maximum%20XOR%20of%20Two%20Numbers%20in%20an%20Array.cpp">Maximum XOR of Two Numbers in an Array (Leetcode-421)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Complement%20of%20Base%2010%20Integer">Complement of Base 10 Integer (Leetcode-1009)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Concatenation%20of%20Consecutive%20Binary%20Numbers">Concatenation of Consecutive Binary Numbers (Leetcode-1680)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Maximum%20XOR%20With%20an%20Element%20From%20Array">Maximum XOR With an Element From Array (Leetcode-1707)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Check%20If%20a%20String%20Contains%20All%20Binary%20Codes%20of%20Size%20K">Check If a String Contains All Binary Codes of Size K (Leetcode-1461)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Maximum_Product_of_Word_Lengths.cpp">Maximum Product of Word Lengths (Leetcode-318)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Gray%20Code.cpp">Gray Code (Leetcode-89)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Sliding%20Window/Find%20the%20Longest%20Substring%20Containing%20Vowels%20in%20Even%20Counts.cpp">Find the Longest Substring Containing Vowels in Even Counts (Leetcode-1371)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Subsets.cpp">Subsets (Leetcode-78)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Partition%20Array%20Into%20Two%20Arrays%20to%20Minimize%20Sum%20Difference.cpp">Partition Array Into Two Arrays to Minimize Sum Difference (Leetcode-2035)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Calculate%207n%5C8%20without%20using%20division%20and%20multiplication.cpp">Calculate 7n\8 without using division and multiplication</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Minimum%20Flips%20to%20Make%20a%20OR%20b%20Equal%20to%20c.cpp">Minimum Flips to Make a OR b Equal to c (Leetcode - 1318)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Sort%20Integers%20by%20The%20Number%20of%201%20Bits.cpp"> Sort Integers by The Number of 1 Bits (Leetcode - 1356)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Find%20The%20Original%20Array%20of%20Prefix%20Xor.cpp"> Find The Original Array of Prefix Xor (Leetcode - 2433)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Number%20of%201%20Bits.cpp"> Number of 1 Bits (Leetcode - 191)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Minimum%20One%20Bit%20Operations%20to%20Make%20Integers%20Zero.cpp"> Minimum One Bit Operations to Make Integers Zero (Leetcode - 1611)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Maximum%20Number%20That%20Sum%20of%20the%20Prices%20Is%20Less%20Than%20or%20Equal%20to%20K.cpp"> Maximum Number That Sum of the Prices Is Less Than or Equal to K (Leetcode - 3007)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Maximum%20Length%20of%20a%20Concatenated%20String%20with%20Unique%20Characters.cpp"> Maximum Length of a Concatenated String with Unique Characters (Leetcode - 1239)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Bitwise%20AND%20of%20Numbers%20Range.cpp"> Bitwise AND of Numbers Range (Leetcode - 201)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Minimum%20Number%20of%20Operations%20to%20Make%20Array%20XOR%20Equal%20to%20K.cpp"> Minimum Number of Operations to Make Array XOR Equal to K (Leetcode - 2997)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Number%20of%20Wonderful%20Substrings.cpp"> Number of Wonderful Substrings (Leetcode - 1915)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Score%20After%20Flipping%20Matrix.cpp"> Score After Flipping Matrix (Leetcode - 861)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Number%20of%20Steps%20to%20Reduce%20a%20Number%20in%20Binary%20Representation%20to%20One.cpp"> Number of Steps to Reduce a Number in Binary Representation to One (Leetcode - 1404)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Count%20Triplets%20That%20Can%20Form%20Two%20Arrays%20of%20Equal%20XOR.cpp"> Count Triplets That Can Form Two Arrays of Equal XOR (Leetcode - 1442)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/XOR%20Queries%20of%20a%20Subarray.cpp"> XOR Queries of a Subarray (Leetcode - 1310)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Largest%20Combination%20With%20Bitwise%20AND%20Greater%20Than%20Zero.cpp"> Largest Combination With Bitwise AND Greater Than Zero (Leetcode - 2275)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Maximum%20XOR%20for%20Each%20Query.cpp"> Maximum XOR for Each Query (Leetcode - 1829)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Minimum%20Array%20End.cpp"> Minimum Array End (Leetcode - 3133)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Shortest%20Subarray%20With%20OR%20at%20Least%20K%20II.cpp"> Shortest Subarray With OR at Least K II (Leetcode - 3097)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Minimize%20XOR.cpp"> Minimize XOR (Leetcode - 2429)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Neighboring%20Bitwise%20XOR.cpp"> Neighboring Bitwise XOR (Leetcode - 2683)</a>
				</td>
			</tr>
			<tr>
       				 <td>
					<a href="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Bitwise%20XOR%20of%20All%20Pairings.cpp"> Bitwise XOR of All Pairings (Leetcode - 2425)</a>
				</td>
			</tr>
		</tbody>
</table>
