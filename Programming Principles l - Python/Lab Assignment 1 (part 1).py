import math

second = input("Enter the seconds: ")

sec = int(second)


if sec > 86400:
    print("Please enter a value less than or equal to '86,400'")

if sec < 1:
    print("Please enter a value greater than 0 ")

if sec <= 86400 and sec >= 1:
    hours = sec / 60 / 60

    minutes = (hours - int(hours)) * 60

    seconds = int((minutes - int(minutes)) * 60)

    hours = int(hours)
    minutes = int(((sec / 60 / 60) - int(hours)) * 60)

    print(str(hours) + " hours, " + str(minutes) + " minutes, " + str(seconds) + " seconds")
    print("On a 24-hour clock:  " + str(hours) + ":" + str(minutes) + ":" + str(seconds))
