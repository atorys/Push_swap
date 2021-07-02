
``` console
                                     d8
                                     88
          88d888b. dP    dP ,d888'   88d8888b.        ,d888'   dP  dP  dP .d8888b. 88d888b.
          88'  '88 88    88 Y8ooooo. 88'   `88        Y8ooooo. 88  88  88 88'  `88 88'  '88
          88.  .88 88.  .88       88 88     88              88 88.88b.88' 88.  .88 88.  .88
          8Y888P'  `888888' `88888P' 8P     dP d8888P `88888P' 8888P Y8P  `88888P8 8Y888P' 
          88                                                                       88
          8P                                                                       8P
```

<details> <summary> <b> :pushpin: Navigation </b> </summary>

</details>

# Introduction to push_swap 

42 School algorithm project **push_swap**: the aim is to sort data using only two stacks and a limited set of instructions.  Norminette codestyle. 
 [**subject.pdf**](https://cdn.intra.42.fr/pdf/pdf/23502/en.subject.pdf)  
___
[![forthebadge ](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
___
``` bash
./push_swap ０ １ ２ ３ ４ ５ ６
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
