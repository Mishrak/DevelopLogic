l_var1 = float(input('Enter the base value of the local variable 1 = '))
l_var2 = float(input('Enter the base value of the local variable 2 = '))

print(f'Before Swapping\nl_var1 = {l_var1} : l_var2 = {l_var2}\n')
l_temp = l_var1
l_var1 = l_var2
l_var2 = l_temp
print(f'\nAfter Swapping\nl_var1 = {l_var1} : l_var2 = {l_var2}\n')