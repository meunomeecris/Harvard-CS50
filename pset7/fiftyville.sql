-- Keep a log of any SQL queries you execute as you solve the mystery.

-- CRIME SCENE --------------------------------------
SELECT description
FROM crime_scene_reports
WHERE year = 2024
    AND month = 7
    AND day = 28
    AND street = 'Humphrey Street';

-- INTERVIEWS --------------------------------------
SELECT transcript
FROM interviews
WHERE year = 2024
    AND month = 7
    AND day = 28
    AND transcript LIKE '%bakery%';

-- MAIN SUSPECTS --------------------------------------
-- Suspects that was preseting at Parking lot, ATM and made a call less then 60;
SELECT people.name, people.passport_number FROM people
JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
JOIN phone_calls ON people.phone_number = phone_calls.caller
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE bakery_security_logs.year = 2024
    AND bakery_security_logs.month = 7
    AND bakery_security_logs.day = 28
    AND bakery_security_logs.activity = 'exit'
    AND phone_calls.year = 2024
    AND phone_calls.month = 7
    AND phone_calls.day = 28
    AND phone_calls.duration <=60
    AND atm_transactions.year = 2024
    AND atm_transactions.month = 7
    AND atm_transactions.day = 28
    AND atm_transactions.atm_location = 'Leggett Street'
    AND atm_transactions.transaction_type = 'withdraw'
    GROUP BY name;

/*
+--------+-----------------+
|  name  | passport_number |
+--------+-----------------+
| Bruce  | 5773159633      |
| Diana  | 3592750733      |
| Taylor | 1988161715      |
+--------+-----------------+
*/

-- AIRPORT AND FLIGHTS --------------------------------------
-- The informations about the early flight on 07/29/2024 FROM Fiftyville
SELECT  flights.id as [id destination flights], flights.destination_airport_id, destination_airports.city
FROM airports AS origin_airports
JOIN flights ON origin_airports.id = flights.origin_airport_id
JOIN airports AS destination_airports ON flights.destination_airport_id = destination_airports.id
WHERE flights.year = 2024
    AND flights.month = 7
    AND flights.day = 29
    AND origin_airports.city = 'Fiftyville'
    ORDER BY flights.hour ASC
    LIMIT 1;

/*
+------------------------+------------------------+---------------+
| id destination flights | destination_airport_id |     city      |
+------------------------+------------------------+---------------+
| 36                     | 4                      | New York City |
+------------------------+------------------------+---------------+
*/


-- List of people that the suspects called
SELECT suspect.name, accomplice.name, accomplice.passport_number FROM phone_calls
JOIN people AS suspect ON phone_calls.caller = suspect.phone_number
JOIN people AS accomplice ON phone_calls.receiver = accomplice.phone_number
WHERE suspect.name IN ('Bruce', 'Diana', 'Taylor')
  AND phone_calls.year = 2024
  AND phone_calls.month = 7
  AND phone_calls.day = 28
  AND phone_calls.duration <= 60;

/*
+--------+--------+-----------------+
|  name  |  name  | passport_number |
+--------+--------+-----------------+
| Bruce  | Robin  | NULL            |
| Taylor | James  | 2438825627      |
| Diana  | Philip | 3391710505      |
+--------+--------+-----------------+
*/

-- No accumplice was in the flight to NY
-- ELimine Diana from suspect leaving just BRUCE and TAYLOR
SELECT name FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON passengers.flight_id = flights.id
WHERE people.name IN ('Bruce', 'Diana', 'Taylor', 'Robin', 'James', 'Philip')
    AND flights.year = 2024
    AND flights.month = 7
    AND flights.day = 29
    AND flights.id = 36;

/*
+--------+
|  name  |
+--------+
| Bruce  |
| Taylor |
+--------+
*/

-- Check the time the suspect leaves the crime scene
SELECT bakery_security_logs.minute, people.name FROM people
JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
WHERE bakery_security_logs.year = 2024
    AND bakery_security_logs.month = 7
    AND bakery_security_logs.day = 28
    AND bakery_security_logs.activity = 'exit'
    AND people.name in ('Taylor', 'Bruce');
/*
+--------+--------+
| minute |  name  |
+--------+--------+
| 18     | Bruce  |
| 35     | Taylor |
+--------+--------+
*/

-- Bruce leaves the bakery 3 minutes after the time of the crime!
-- Elementary, my dear Watson, Bruce is the thief who escaped to NY, and Robin is the accomplice.