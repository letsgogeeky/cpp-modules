import os
import time
import sys

# Colors
B_PINK  = "\033[1;38;2;255;182;193m"
RESET   = "\033[0m"

frames = [
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |          |  | | | | |     
     |     |__________|  |_|  "' |     
     |.--'                   `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |          |  | | | | |     
     |     |__.____'__|  |_|  "' |     
     |.--'       .           `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |          |  | | | | |     
     |     |__._`_:x__|  |_|  "' |     
     |.--'    .  :  '        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |   .   _  |  | | | | |     
     |     |_`._`_|x._|  |_|  "' |     
     |.--'    :. |  :        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |   +   _  |  | | | | |     
     |     |_`:\ _|,:_|  |_|  "' |     
     |.--'    |. T--|        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |   o   _  |  | | | | |     
     |     |_\:\ _(_> |  |_|  "' |     
     |.--'    |:.T  T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |   o   _  |  | | | | |     
     |     |_\(\ _(_> |  |_|  "' |     
     |.--'    |\.T  T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |   o   _  |  | | | | |     
     |     |_\(\ _(_> |  |_|  "' |     
     |.--'    |\.T  T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |   o   _  |  | | | | |     
     |     |_\(\._(_> |  |_|  "' |     
     |.--'    |\.T  T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |   o   _  |  | | | | |     
     |     |_\(\/_(_> |  |_|  "' |     
     |.--'    |\.T  T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |    .     .--. | | | |     
     |     |   o   _  |  | | | | |     
     |     |_\(\._(_> |  |_|  "' |     
     |.--'    |\.T  T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |     ?    .--. | | | |     
     |     |   o   _  |  | | | | |     
     |     |_\(\._(_> |  |_|  "' |     
     |.--'    |\.T  T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |      .        |  _. |     
     |     |   ` ? -  .--. | | | |     
     |     |   o   _  |  | | | | |     
     |     |_\(\ _(_> |  |_|  "' |     
     |.--'    |\.T  T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |   . ?    .--. | | | |     
     |     |   o  '_  |  | | | | |     
     |     |_\(\._(_> |  |_|  "' |     
     |.--'    |\.T  T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |     .    .--. | | | |     
     |     |   o   _  |  | | | | |     
     |     |_\(\._(_> |  |_|  "' |     
     |.--'    |\.T  T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |   o   _  |  | | | | |     
     |     |_\(\/_(_> |  |_|  "' |     
     |.--'    |\.T  T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |   o   _  |  | | | | |     
     |     |_\(\._(_> |  |_|  "' |     
     |.--'    |\.T  T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |    .     .--. | | | |     
     |     |   o ' _  |  | | | | |     
     |     |_\(\._(_> |  |_|  "' |     
     |.--'    |\.T  T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |    .          |  _. |     
     |     |   - ! '  .--. | | | |     
     |     |   o   _  |  | | | | |     
     |     |_\(\/_(_> |  |_|  "' |     
     |.--'    |\.T  T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |     .         |  _. |     
     |     |  ` !!! - .--. | | | |     
     |     |   o ' _  |  | | | | |     
     |     |_\(\._(_> |  |_|  "' |     
     |.--'    |\.T  T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |  .   '        |  _. |     
     |     |    ! ! . .--. | | | |     
     |     |   o   _  |  | | | | |     
     |     |_\(\ _(_> |  |_|  "' |     
     |.--'    |\.T  T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |   . ',   .--. | | | |     
     |     |   o   _  |  | | | | |     
     |     |_\(\._(_> |  |_|  "' |     
     |.--'    |\.T  T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |     .    .--. | | | |     
     |     |   o   _  |  | | | | |     
     |     |_\(\/_(_> |  |_|  "' |     
     |.--'    |\.T  T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |     .    .--. | | | |     
     |     |   o'  _  |  | | | | |     
     |     |_\(\._(_> |  |_|  "' |     
     |.--'    |\.T  T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |        ,      |  _. |     
     |     |   - GR.  .--. | | | |     
     |     |   o'  _  |  | | | | |     
     |     |_\(\/_(_> |  |_|  "' |     
     |.--'    |\.T  T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |  .            |  _. |     
     |     | - GRF `  .--. | | | |     
     |     |   o'  _  |  | | | | |     
     |     |_\(\._(_> |  |_|  "' |     
     |.--'    |\.T  T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |  ,  .         |  _. |     
     |     | - RFZL - .--. | | | |     
     |     |   o' `_  |  | | | | |     
     |     |_\(\/_(_> |  |_|  "' |     
     |.--'    |\.T  T        `--.|     
     """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |   .           |  _. |     
     |     | - FZ'-   .--. | | | |     
     |     |   o'  _  |  | | | | |     
     |     |_\(\._(_> |  |_|  "' |     
     |.--'    |\.T  T        `--.|     
    """,

    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |  - .'    .--. | | | |     
     |     |   o   _  |  | | | | |     
     |     |_\<|\_(_> |  |_|  "' |     
     |.--'    |>.T  T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |  `   .   .--. | | | |     
     |     |    o  _  |  | | | | |     
     |     |_\_< \(_> |  |_|  "' |     
     |.--'    | |T  T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |     o _  |  | | | | |     
     |     |_\_ (\(_> |  |_|  "' |     
     |.--'    |/|T  T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |     o_   |  | | | | |     
     |     |_\_ ((_>  |  |_|  "' |     
     |.--'    |/|T  T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |    o_    |  | | | | |     
     |     |_\_<(_>   |  |_|  "' |     
     |.--'    |/|T  T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |    o_    |  | | | | |     
     |     |_\_ (_>   |  |_|  "' |     
     |.--'    | |\--T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |     o_   |  | | | | |     
     |     |_\_  (_>  |  |_|  "' |     
     |.--'    | />--T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |      o_  |  | | | | |     
     |     |_\_  <(_> |  |_|  "' |     
     |.--'    |  /| T        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |       o_ |  | | | | |     
     |     |_\_ _ <(_>|  |_|  "' |     
     |.--'    |  T |\        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |        o_|  | | | | |     
     |     |_\_ ___ (_>  |_|  "' |     
     |.--'    |  T .|        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |         o_  | | | | |     
     |     |_\_ ____ (_> |_|  "' |     
     |.--'    |  T--/|       `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |          o_ | | | | |     
     |     |_\_ _____ (_>|_|  "' |     
     |.--'    |  T  T.>      `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |          o_ | | | | |     
     |     |_\_ _____<(_>|_|  "' |     
     |.--'    |  T  T >>     `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |          o _  | | | |     
     |     |_\_ _____ \(_>_|  "' |     
     |.--'    |  T  T >>     `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--_ | | | |     
     |     |          o (_>| | | |     
     |     |_\_ _____ |-  _|  "' |     
     |.--'    |  T  T >>     `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |              _   _. |     
     |     |          .- (_> | | |     
     |     |          o_.    | | |     
     |     |_\_ _____ |  |_|  "' |     
     |.--'    |  T  T >>     `--.|     

    """,

    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               _  _. |     
     |     |          .-- (_>| | |     
     |     |          o      | | |     
     |     |_\_ _____ |\ |_|  "' |     
     |.--'    |  T  T |>     `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |                _ _. |     
     |     |          .--. (_> | |     
     |     |          o  |   | | |     
     |     |_\_ _____ <  |_|  "' |     
     |.--'    |  T  T |.     `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--.   _ | |     
     |     |          o  |  (_>| |     
     |     |_\_ _____< > |_|  "' |     
     |.--'    |  T  T |      `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | |_| |     
     |     |          o  | | ( | |     
     |     |_\_ _____< > |_|  "' |     
     |.--'    |  T  T |      `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |          o  | | |(| |     
     |     |_\_ _____< > |_|  "' |     
     |.--'    |  T  T |      `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |          o  | | | | |     
     |     |_\_ _____< > |_|  "' |     
     |.--'    |  T  T |      `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |          o  | | | | |>    
     |     |_\_ _____< > |_|  "' |     
     |.--'    |  T  T |      `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |          o  | | | | |_    
     |     |_\_ _____< > |_|  "' |_>   
     |.--'    |  T  T |      `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |          o  | | | | |     
     |     |_\_ _____< > |_|  "' |'_.  
     |.--'    |  T  T |      `--.| _>- 
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |          o  | | | | | .   
     |     |_\_ _____< > |_|  "' |`+/.-
     |.--'    |  T  T |      `--.|*R ' 
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |          o  | | | | | ' . 
     |     |_\_ _____< > |_|  "' |     
     |.--'    |  T  T |      `--.|.x, .
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |          o  | | | | |    .
     |     |_\_ _____< > |_|  "' |     
     |.--'    |  T  T |      `--.|.x,  
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |          o  | | | | |     
     |     |_\_ _____< > |_|  "' |     
     |.--'    |  T  T |      `--.|.x,  
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |          o  | | | | |     
     |     |_\_ _ __ < > |_|  "' |     
     |.--'    :  |  | :      `--.|.x,  
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |          o  | | | | |     
     |     |___ _ ___  . |_|  "' |     
     |.--'    .  :  | '      `--.|.-.  
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |          .  | | | | |     
     |     |_____ ____ . |_|  "' |     
     |.--'    .  . `:        `--.| .   
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |          |  | | | | |     
     |     |__________ . |_|  "' |     
     |.--'          .        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |          |  | | | | |     
     |     |__________|  |_|  "' |     
     |.--'          .        `--.|     
    """,
    r"""
     |`"-. _________________ .-"'|     
     |     |- a:f -        |     |     
     |     |               |  _. |     
     |     |          .--. | | | |     
     |     |          |  | | | | |     
     |     |__________|  |_|  "' |      
     |.--'                   `--.|     
    """
]

def clear():
    os.system('printf "\033c"')

def animate():
    stop_file = "stop_animation.txt" 
    try:
        while not os.path.exists(stop_file):
            for frame in frames:
                if os.path.exists(stop_file):
                    break
                clear()
                print(frame)
                time.sleep(0.1)
    finally:
        if os.path.exists(stop_file):
            os.remove(stop_file)
    clear()
    print(f"""
     |`"-. _________________ .-"'|     
     |     | -{B_PINK} Build 💪💪{RESET}  |     |     
     |     |    {B_PINK}complete!{RESET}- |  _. |     
     |     |          .--. | | | |     
     |     |          |  | | | | |     
     |     |__________|  |_|  "' |      
     |.--'                   `--.|     
    """)
    sys.exit()

if __name__ == "__main__":
  animate()