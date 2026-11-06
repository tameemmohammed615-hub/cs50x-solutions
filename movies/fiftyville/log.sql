-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Keep track of the queries used to solve the mystery
SELECT name, transcript FROM interviews WHERE year = 2025 AND month = 7 AND day = 28;
SELECT description FROM crime_scene_reports WHERE year = 2025 AND month = 7 AND day = 28;
SELECT license_plate FROM bakery_security_logs WHERE year = 2025 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25 AND activity = 'exit';
SELECT account_number FROM atm_transactions WHERE year = 2025 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';
SELECT flights.id, flights.hour, flights.minute, airports.city FROM flights JOIN airports ON flights.destination_airport_id = airports.id WHERE flights.origin_airport_id = (SELECT id FROM airports WHERE city = 'Fiftyville') AND flights.year = 2025 AND flights.month = 7 AND flights.day = 29 ORDER BY flights.hour ASC, flights.minute ASC LIMIT 1;
