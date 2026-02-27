total_seconds=int(input("Enter a large number"))
hours=total_seconds//3600
remaining_seconds=total_seconds%3600
minutes=remaining_seconds//60
seconds=remaining_seconds%60
print(f"{total_seconds} seconds is {hours}hours, {minutes}minutes, and {seconds}seconds.")

