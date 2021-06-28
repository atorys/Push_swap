# Push_swap

## Operations
**A  B**  
5  
1  
3  
4  
2

<table>
  <tr><td>
    
    <table>
      <tr><td> A </td><td> B </td></tr>
      <tr><td> A </td><td> B </td></tr>
      <tr><td> A </td><td> B </td></tr>
      <tr><td> A </td><td> B </td></tr>
      <tr><td> A </td><td> B </td></tr>
    </table>
    
    </td><td>
    
    <table>
      <tr><td> A </td><td> B </td></tr>
      <tr><td> A </td><td> B </td></tr>
      <tr><td> A </td><td> B </td></tr>
      <tr><td> A </td><td> B </td></tr>
      <tr><td> A </td><td> B </td></tr>
    </table>
    
  </td></tr>
</table>

### **swap a / swap b:**  
swap first two elements at the top of choosen stack  
**A:** `1` `5` 3 4 2

**A:**
`1` `5`2 4 3

| A | A' |
|:----:|:----:|
| `3` | `2` |
| `2` | `3` | 
| 1 | 1 |

### **pa** push a - take the first element at the top of b and put it at the top of a
|    A | B   | | A    | B   |
|:----:|:----:|-|:----:|:----:|
| 3 | `4` | | `4` | 5 |
| 2 | 5 | | 3 | 6 | 
|   | 6   | | 4 | 

<html>
<head>
<style type="text/css">
table.t1
{
   display: inline;
}
</style>
</head>
<body>
<table class="t1">
  <tr><td>1</td><td>2</td></tr>
  <tr colspan="2"><td>3</td></tr>
</table>
<table class="t1">
  <tr><td>5</td><td>6</td></tr>
  <tr colspan="2"><td>7</td></tr>
</table>
</body>
</html>
