# Todo list

- Server

  - Mysql setup
  - REST api to access the said mysql database
  - Mechanism to distribute problem

- Client
  - Connect to server
  - Get data
  - Porpagate
  - Update server

# Resources

- https://github.com/dbohdan/automatic-api
- https://github.com/pyeve/eve
- https://app.quickdatabasediagrams.com/#/
- https://sandman2.readthedocs.io/en/latest/index.html

```sql https://app.quickdatabasediagrams.com/#/
SatTypes
-
id int
description string


Orbit
-
id PK int
type  int FK >- SatTypes.id


TLE
-
id PK int
updated_at timestamp
orbit_id int FK >- Orbit.id
tle_message string

Propagation
-
tle_id int FK >- TLE.id
  time timestamp
  sector_id int
  x float
  y float
  z float
  vx float
  vy float
  vz float

```
