       
   0000000
   000000000000
   88888````000000
   88888    000000
   8888888888888``
   88888```````
   88880
   88880
   `````


# Push_swap
[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/you-didnt-ask-for-this.svg)](https://forthebadge.com)  


42 School algorithm project **push_swap**: the aim is to sort data using only two stacks and a limited set of instructions.  Norminette codestyle.  
[**subject.pdf**](https://cdn.intra.42.fr/pdf/pdf/23502/en.subject.pdf)

``` bash
./push_swap 
```


０ １ ２ ３ ４ ５ ６ 

## Set of instructions
 **A:**  ­­­ ５  ­ １ ­ ３ ­ ４ ­ ２  
 **B:**  ­­­ is empty
### **swap a / swap b:**  
> **A:** `５⥂１` ­ ３ ­ ４ ­ ２  
> **SA:** １ ­ ５ ­ ３ ­ ４ ­ ２  
swap first two elements at the top of choosen stack  

### push b:
> **A:**  `..` ５ ­ ３ ­ ４ ­２  
> **B:**  `１`

### rotate a
> **A:** `５` ­ ３ ­ ４ ­ ２    
> **RA:** ３ ­ ４ ­ ２ ­ `５` 
