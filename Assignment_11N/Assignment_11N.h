Please enter the name of the file to be open:
--> MinPath1.txt

Graph:
   0:             SF;  [ ( LA, 80 ) ( CHICAGO, 200 ) ( NY, 300 ) ]
   1:             LA;  [ ( SF, 80 ) ( CHICAGO, 230 ) ( LONDON, 700 ) ]
   2:        CHICAGO;  [ ( SF, 200 ) ( LA, 230 ) ( NY, 180 ) ]
   3:             NY;  [ ( SF, 300 ) ( CHICAGO, 180 ) ( PARIS, 630 ) ( LONDON, 500 ) ]
   4:          PARIS;  [ ( NY, 630 ) ( LONDON, 140 ) ]
   5:         LONDON;  [ ( LA, 700 ) ( NY, 500 ) ( PARIS, 140 ) ]

Please enter the start vertex: (Press enter to exit)
--> SF
Please enter the end vertex:
--> LA
Minimal path from 'SF' to 'LA': SF LA 80

Please enter the start vertex: (Press enter to exit)
--> SF
Please enter the end vertex:
--> CHICAGO
Minimal path from 'SF' to 'CHICAGO': SF CHICAGO 200

Please enter the start vertex: (Press enter to exit)
--> SF
Please enter the end vertex:
--> LONDON
Minimal path from 'SF' to 'LONDON': SF LA LONDON 780

Please enter the start vertex: (Press enter to exit)
--> SF
Please enter the end vertex:
--> PARIS
Minimal path from 'SF' to 'PARIS': SF NY PARIS 930

Please enter the start vertex: (Press enter to exit)
--> PARIS
Please enter the end vertex:
--> CHICAGO
Minimal path from 'PARIS' to 'CHICAGO': PARIS NY CHICAGO 810

Please enter the start vertex: (Press enter to exit)
-->





Please enter the name of the file to be open:
--> MinPath2.txt

Graph:
   0:             SF;  [ ( LA, 40 ) ( DALLAS, 100 ) ( PHOENIX, 130 ) ( NY, 200 ) ( LONDON, 800 ) ( PARIS, 900 ) ]
   1:             LA;  [ ( SF, 40 ) ( DALLAS, 50 ) ( CONCORD, 80 ) ( PHOENIX, 70 ) ( NY, 400 ) ( PARIS, 1200 ) ( BANGKOK, 900 ) ]
   2:         DALLAS;  [ ( SF, 100 ) ( LA, 50 ) ( ST LOUIS, 120 ) ( BOSTON, 110 ) ( MEXICO CITY, 700 ) ( MONTREAL, 600 ) ]
   3:        CONCORD;  [ ( LA, 80 ) ( CHICAGO, 30 ) ( ST LOUIS, 50 ) ( NY, 450 ) ]
   4:        PHOENIX;  [ ( SF, 130 ) ( LA, 70 ) ( CHICAGO, 50 ) ( NY, 300 ) ( MEXICO CITY, 350 ) ]
   5:        CHICAGO;  [ ( CONCORD, 30 ) ( PHOENIX, 50 ) ( BOSTON, 40 ) ( NY, 100 ) ( LONDON, 475 ) ( TOKYO, 650 ) ]
   6:       ST LOUIS;  [ ( DALLAS, 120 ) ( CONCORD, 50 ) ( BOSTON, 60 ) ( NY, 195 ) ( MONTREAL, 80 ) ]
   7:         BOSTON;  [ ( DALLAS, 110 ) ( CHICAGO, 40 ) ( ST LOUIS, 60 ) ( NY, 65 ) ( LONDON, 425 ) ( PARIS, 700 ) ( MONTREAL, 325 ) ]
   8:             NY;  [ ( SF, 200 ) ( LA, 400 ) ( CONCORD, 450 ) ( PHOENIX, 300 ) ( CHICAGO, 100 ) ( ST LOUIS, 195 ) ( BOSTON, 65 ) ( LONDON, 325 ) ( PARIS, 600 ) ( TOKYO, 700 ) ( BANGKOK, 550 ) ]
   9:         LONDON;  [ ( SF, 800 ) ( CHICAGO, 475 ) ( BOSTON, 425 ) ( NY, 325 ) ( PARIS, 60 ) ( BANGKOK, 400 ) ]
  10:          PARIS;  [ ( SF, 900 ) ( LA, 1200 ) ( BOSTON, 700 ) ( NY, 600 ) ( LONDON, 60 ) ( MEXICO CITY, 200 ) ]
  11:          TOKYO;  [ ( CHICAGO, 650 ) ( NY, 700 ) ( BANGKOK, 125 ) ( MEXICO CITY, 400 ) ]
  12:        BANGKOK;  [ ( LA, 900 ) ( NY, 550 ) ( LONDON, 400 ) ( TOKYO, 125 ) ( MEXICO CITY, 350 ) ]
  13:    MEXICO CITY;  [ ( DALLAS, 700 ) ( PHOENIX, 350 ) ( PARIS, 200 ) ( TOKYO, 400 ) ( BANGKOK, 350 ) ( MONTREAL, 700 ) ]
  14:       MONTREAL;  [ ( DALLAS, 600 ) ( ST LOUIS, 80 ) ( BOSTON, 325 ) ( MEXICO CITY, 700 ) ]

Please enter the start vertex: (Press enter to exit)
--> PHOENIX
Please enter the end vertex:
--> SF
Minimal path from 'PHOENIX' to 'SF': PHOENIX SF 130

Please enter the start vertex: (Press enter to exit)
--> PHOENIX
Please enter the end vertex:
--> LA
Minimal path from 'PHOENIX' to 'LA': PHOENIX LA 70

Please enter the start vertex: (Press enter to exit)
--> PHOENIX
Please enter the end vertex:
--> DALLAS
Minimal path from 'PHOENIX' to 'DALLAS': PHOENIX LA DALLAS 120

Please enter the start vertex: (Press enter to exit)
--> PHOENIX
Please enter the end vertex:
--> CONCORD
Minimal path from 'PHOENIX' to 'CONCORD': PHOENIX CHICAGO CONCORD 80

Please enter the start vertex: (Press enter to exit)
--> PHOENIX
Please enter the end vertex:
--> CHICAGO
Minimal path from 'PHOENIX' to 'CHICAGO': PHOENIX CHICAGO 50

Please enter the start vertex: (Press enter to exit)
--> PHOENIX
Please enter the end vertex:
--> PHOENIX
Target is not found
Please enter the start vertex: (Press enter to exit)
--> PHOENIX
Please enter the end vertex:
--> ST LOUIS
Minimal path from 'PHOENIX' to 'ST LOUIS': PHOENIX CHICAGO CONCORD ST LOUIS 130

Please enter the start vertex: (Press enter to exit)
--> PHOENIX
Please enter the end vertex:
--> BOSTON
Minimal path from 'PHOENIX' to 'BOSTON': PHOENIX CHICAGO BOSTON 90

Please enter the start vertex: (Press enter to exit)
--> PHOENIX
Please enter the end vertex:
--> NY
Minimal path from 'PHOENIX' to 'NY': PHOENIX NY 300

Please enter the start vertex: (Press enter to exit)
--> PHOENIX
Please enter the end vertex:
--> LONDON
Minimal path from 'PHOENIX' to 'LONDON': PHOENIX CHICAGO LONDON 525

Please enter the start vertex: (Press enter to exit)
--> PHOENIX
Please enter the end vertex:
--> PAris

Error: Requested vertex not found:  'PAris'

Please enter the start vertex: (Press enter to exit)
--> PHOENIX
Please enter the end vertex:
--> PARIS
Minimal path from 'PHOENIX' to 'PARIS': PHOENIX LA PARIS 1270

Please enter the start vertex: (Press enter to exit)
--> PHOENIX
Please enter the end vertex:
--> TOKYO
Minimal path from 'PHOENIX' to 'TOKYO': PHOENIX CHICAGO TOKYO 700

Please enter the start vertex: (Press enter to exit)
--> PHOENIX
Please enter the end vertex:
--> BANGKOK
Minimal path from 'PHOENIX' to 'BANGKOK': PHOENIX LA BANGKOK 970

Please enter the start vertex: (Press enter to exit)
--> PHOENIX
Please enter the end vertex:
--> MEXICO CITY
Minimal path from 'PHOENIX' to 'MEXICO CITY': PHOENIX MEXICO CITY 350

Please enter the start vertex: (Press enter to exit)
--> PHOENIX
Please enter the end vertex:
--> MONTREAL
Minimal path from 'PHOENIX' to 'MONTREAL': PHOENIX CHICAGO BOSTON MONTREAL 415

Please enter the start vertex: (Press enter to exit)
-->