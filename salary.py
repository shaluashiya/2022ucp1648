# Define basic salary and grade
basic_A = 10000
basic_B = 4567
grade_A = 'A'
grade_B = 'B'

# Function to calculate gross salary
def calculate_gross_salary(basic, grade):
    hra = 0.20 * basic
    da = 0.50 * basic
    
    if grade == 'A':
        allowance = 1700
    elif grade == 'B':
        allowance = 1500
    else:
        allowance = 1300
    
    pf = 0.11 * basic
    gross_salary = basic + hra + da + allowance - pf
    return gross_salary

# Calculate and display gross salaries
gross_salary_A = calculate_gross_salary(basic_A, grade_A)
gross_salary_B = calculate_gross_salary(basic_B, grade_B)

print(f"Gross Salary (Grade A): {gross_salary_A}")
print(f"Gross Salary (Grade B): {gross_salary_B}")
