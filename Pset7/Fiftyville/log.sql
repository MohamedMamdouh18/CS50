-- Keep a log of any SQL queries you execute as you solve the mystery.

select description from crime_scene_reports where day = 28 and month = 7 and year = 2020;
-- Theft of the CS50 duck took place at (10:15am) at the Chamberlin Street courthouse.
--Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.


select transcript from interviews where day = 28 and month = 7 and year = 2020;
--Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away.
--If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.
--I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse,
--I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.
--As the thief was leaving the courthouse, they called someone who talked to them for less than a minute. In the call,
--I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
--The thief then asked the person on the other end of the phone to purchase the flight ticket.


select name from people
join phone_calls on phone_calls.caller = people.phone_number
where year = 2020 and month = 7 and day = 28 and duration < 60
INTERSECT
select name from people
join courthouse_security_logs on courthouse_security_logs.license_plate = people.license_plate
where day = 28 and month = 7 and year = 2020 and activity = "exit" and hour = 10 and minute >= 15 and minute <= 25
INTERSECT
select name from people
join bank_accounts on bank_accounts.person_id = people.id
join atm_transactions on bank_accounts.account_number = atm_transactions.account_number
where day = 28 and month = 7 and year = 2020 and transaction_type = "withdraw" and atm_location = "Fifer Street"
INTERSECT
select name from people
join passengers on passengers.passport_number = people.passport_number
join flights on flights.id = passengers.flight_id
join airports on airports.id = flights.origin_airport_id
where day = 29 and month = 7 and year = 2020 and city = "Fiftyville" and
hour = (select min(hour) from flights where day = 29 and month = 7 and year = 2020 and city = "Fiftyville") ;
--The THIEF is:Ernest


select distinct(name) from people
join phone_calls on phone_calls.receiver = people.phone_number
where receiver =
(select receiver from phone_calls
join people on phone_calls.caller = people.phone_number
where name = "Ernest" and year = 2020 and month = 7 and day = 28 and duration < 60) ;
--The ACCOMPLICE is:Berthold


select city from airports
join flights on flights.destination_airport_id = airports.id
join passengers on flights.id = passengers.flight_id
join people on passengers.passport_number = people.passport_number
where name = "Ernest"
--The thief ESCAPED TO:London
