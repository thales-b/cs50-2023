-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description
FROM crime_scene_reports
WHERE day = 28 AND month = 07 AND street = 'Humphrey Street';

SELECT transcript
FROM interviews
WHERE day = 28
AND month = 07;

SELECT *
FROM people
WHERE license_plate IN (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE day = 28
    AND month = 07
    AND hour = 10
    AND minute >= 15
    AND minute <=30
    AND activity = 'exit'
);

SELECT *
FROM bank_accounts
WHERE person_id IN (
    SELECT id
FROM people
WHERE license_plate IN (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE day = 28
    AND month = 07
    AND hour = 10
    AND minute >= 15
    AND minute <=30
    AND activity = 'exit'
)
);

SELECT *
FROM atm_transactions
WHERE atm_location = 'Leggett Street'
AND month = 07
AND day = 28
AND account_number IN (
    SELECT account_number
FROM bank_accounts
WHERE person_id IN (
    SELECT id
FROM people
WHERE license_plate IN (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE day = 28
    AND month = 07
    AND hour = 10
    AND minute >= 15
    AND minute <=30
    AND activity = 'exit'
)
)
);

SELECT *
FROM people
WHERE id IN
( SELECT person_id
FROM bank_accounts
WHERE account_number IN (
    SELECT account_number
FROM atm_transactions
WHERE atm_location = 'Leggett Street'
AND month = 07
AND day = 28
AND account_number IN (
    SELECT account_number
FROM bank_accounts
WHERE person_id IN (
    SELECT id
FROM people
WHERE license_plate IN (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE day = 28
    AND month = 07
    AND hour = 10
    AND minute >= 15
    AND minute <=30
    AND activity = 'exit'
)
)
)
)
);

--Plate, bank account, id


SELECT *
FROM phone_calls
WHERE month = 07 AND day = 28 AND year = 2021 AND caller IN
(SELECT phone_number
FROM people
WHERE id IN
( SELECT person_id
FROM bank_accounts
WHERE account_number IN (
    SELECT account_number
FROM atm_transactions
WHERE atm_location = 'Leggett Street'
AND month = 07
AND day = 28
AND account_number IN (
    SELECT account_number
FROM bank_accounts
WHERE person_id IN (
    SELECT id
FROM people
WHERE license_plate IN (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE day = 28
    AND month = 07
    AND hour = 10
    AND minute >= 15
    AND minute <=30
    AND activity = 'exit'))))));

    --Bruce

SELECT *
FROM people
WHERE phone_number IN (
SELECT receiver
FROM phone_calls
WHERE month = 07 AND day = 28 AND year = 2021 AND duration <= 100 AND caller IN
(SELECT phone_number
FROM people
WHERE id IN
( SELECT person_id
FROM bank_accounts
WHERE account_number IN (
    SELECT account_number
FROM atm_transactions
WHERE atm_location = 'Leggett Street'
AND month = 07
AND day = 28
AND account_number IN (
    SELECT account_number
FROM bank_accounts
WHERE person_id IN (
    SELECT id
FROM people
WHERE license_plate IN (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE day = 28
    AND month = 07
    AND hour = 10
    AND minute >= 15
    AND minute <=30
    AND activity = 'exit')))))));

--Robin

SELECT *
FROM people p
JOIN phone_calls pc ON p.phone_number = pc.receiver AND pc.caller = '(367) 555-5533'
WHERE pc.day = 28
AND pc.month = 07
AND duration <= 60
ORDER BY pc.id;

--id = 864400, phone_number = '(375) 555-8161'

SELECT *
FROM atm_transactions
WHERE year = 2021
AND day >= 28
AND month = 07
AND account_number = (
    SELECT account_number
    FROM bank_accounts
    WHERE person_id = 864400
);

SELECT f.destination_airport_id
FROM flights f
JOIN airports a ON f.origin_airport_id = a.id
WHERE year = 2021
AND day = 29
AND month = 07
AND a.city = 'Fiftyville'
ORDER BY hour ASC
LIMIT 1;

SELECT *
FROM airports
WHERE id = (
    SELECT f.destination_airport_id
FROM flights f
JOIN airports a ON f.origin_airport_id = a.id
WHERE year = 2021
AND day = 29
AND month = 07
AND a.city = 'Fiftyville'
ORDER BY hour ASC
LIMIT 1
);

SELECT

SELECT f.id
FROM flights f
JOIN airports a ON f.origin_airport_id = a.id
WHERE year = 2021
AND day = 29
AND month = 07
AND a.city = 'Fiftyville'
ORDER BY hour ASC
LIMIT 1;

SELECT passport_number
FROM people
WHERE name = 'Bruce';

SELECT *
FROM passengers
WHERE passport_number = 5773159633
AND flight_id = (
    SELECT f.id
FROM flights f
JOIN airports a ON f.origin_airport_id = a.id
WHERE year = 2021
AND day = 29
AND month = 07
AND a.city = 'Fiftyville'
ORDER BY hour ASC
LIMIT 1
);