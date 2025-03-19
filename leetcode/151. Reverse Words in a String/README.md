# Intuition

* Reverse the entire string
Reverse Individual words while handling the extra spaces
Remofing the extra spaces and returning

# Approach

* initialise `left=0,right=0,current=0;`

![alt text](image.png)

* Reverse the Entire String `reverse(s.begin(),s.end());`

* Skip Leading Spaces `while(i<n && s[i]==' ')i++;`

![alt text](image-1.png)

* Copy Characters of a Word to the correct position
`while(i<n && s[i]!=' '){ s[right++]=s[i++]; }`

![alt text](image-2.png)

* Reverse Individual Words
`reverse(s.begin()+left,s.begin()+right);`

![alt text](image-3.png)

* Add Space Between Words
`s[right++]=' '; left=right;`

![alt text](image-5.png)

* repeat the steps for all the words
  
![alt text](image-6.png)

Finally, it resizes the string to remove any extra space.
` s.resize(right-1);`

![alt text](image-7.png)