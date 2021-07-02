# Push_swap

42 School algorithm project **push_swap**: the aim is to sort data using only two stacks and a limited set of instructions.  Norminette codestyle.  
[**subject.pdf**](https://cdn.intra.42.fr/pdf/pdf/23502/en.subject.pdf)


０ １ ２ ３ ４ ５ ６ 

## Set of instructions
 **A:**  ­­­ ５  ­ １ ­ ３ ­ ４ ­ ２  
 **B:**  ­­­ is empty
### **swap a / swap b:**  
> **A:** `５⥂１` ­ ３ ­ ４ ­ ２  
> **SA** １ ­ ５ ­ ３ ­ ４ ­ ２  
swap first two elements at the top of choosen stack  

### push b:
> **A:**  `..` ５ ­ ３ ­ ４ ­２  
> **B:**  `１`

### rotate a
> **A:** `５` ­ ３ ­ ４ ­ ２    
> **RA:** ３ ­ ４ ­ ２ ­ `５` 
