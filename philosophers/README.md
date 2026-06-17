# Philosophers

*This project has been created as part of the 42 curriculum by asgalean.*

---

## Description

A classic implementation of the Dining Philosophers problem using POSIX threads and mutexes. A given number of philosophers sit around a table sharing forks, cycling through eating, sleeping, and thinking. The goal is to keep every philosopher alive — fed before their personal "time to die" runs out — without deadlocking, while logging every state change with a millisecond-accurate timestamp.

Key features:
- One thread per philosopher (`pthread_create`), each running an independent eat → sleep → think loop
- One mutex per fork, plus a shared print mutex so log lines never interleave mid-line
- Continuous death detection by comparing each philosopher's time since their last meal against `time_to_die`
- Optional stop condition: the simulation ends once every philosopher has eaten `number_of_times_each_must_eat` times
- Edge case handling for a single philosopher (only one fork exists, so they simply starve)
- Hand-rolled input parsing and validation (no `atoi`, custom `pseudo_atoi` with overflow checks)

---------------

## Instructions

### Compilation

```bash
make
```

```bash
make clean   # remove object files
make fclean  # remove object files + binary
make re      # full rebuild
```

### Execution

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

- `number_of_philosophers` — number of philosophers and forks at the table
- `time_to_die` — milliseconds a philosopher can go without eating before dying
- `time_to_eat` — milliseconds spent eating once both forks are picked up
- `time_to_sleep` — milliseconds spent sleeping after eating
- `number_of_times_each_philosopher_must_eat` *(optional)* — if provided, the simulation stops once every philosopher has reached this many meals

Example:
```bash
./philo 5 800 200 200
```

### Log format

```
<timestamp_ms>ms	Philo <id>: has TAKEN his fork
<timestamp_ms>ms	Philo <id>: has TAKEN the next fork
<timestamp_ms>ms	Philo <id>: is EATING
<timestamp_ms>ms	Philo <id>: is SLEEPING
<timestamp_ms>ms	Philo <id>: is THIKNING
<timestamp_ms>ms	Philo <id>: DIED
```
