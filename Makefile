# Comment utiliser ce Makefile ?
# 
#	Avant de le lancer, vérifiez votre arborescence. Vous devez avoir 3 dossiers src, inc et bin.
#	Sinon vous devez editer les variable SRC_DIR, INC_DIR et BIN_DIR en conséquence.
#	Vous devez changer les SRCS pour qu'elles correspondent avec les noms de vos fichiers source.
# 
#	Mettez vous dans un shell dans le meme dossier que la ou se trouve le Makefile
# 	Lancer une des commandes suivantes:
# 		`make`				->		Compile vos sources et cree un executable
# 		`make clean`		->		Supprime vos fichiers binaires
# 		`make fclean`		->		Supprime vos fichiers binaires et votre executable
# 		`make re`			->		Fait un `make flcean` puis un `make`

# Le nom du dossier ou vous mettez vos sources
SRC_DIR				= src
# Le nom du dossier ou vous mettez vos headers
INC_DIR				= inc
# Le nom du dossier ou vous mettez vos binaires
BIN_DIR				= bin
# La liste des fichiers a compiler
SRCS				= main.cpp GameManager.cpp Data.cpp Initializer.cpp Player.cpp Props.cpp load_media.cpp utils.cpp
OBJS				= ${addprefix ${BIN_DIR}/,${SRCS:.cpp=.o}}
CC					= g++
# Vos flags de compilation
CFLAGS				= -g 
# Les chemins vers les headers necessaire, les votres et ceux de la SDL
INC_PATH			= -Iinc -IC:\Tout\Logiciel\LibsSdl\LibSdl\include\SDL2 -IC:\Tout\Logiciel\LibsSdl\LibSdlImage\include\SDL2
LIB_PATH			= -LC:\Tout\Logiciel\LibsSdl\LibSdl\lib -LC:\Tout\Logiciel\LibsSdl\LibSdlImage\lib
# Les noms des librairies qu'on utilise
LIB					= -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
# Nom du cmdlet pour supprimer un fichier sur Windows
RM					= del
# Le nom de l'executable
TARGET				= a.exe

###										###
###	NE RIEN CHANGER APRES CETTE LIGNE	###
###										###

${BIN_DIR}/%.o :	${SRC_DIR}/%.cpp
					${CC} ${CFLAGS} ${INC_PATH} ${LIB_PATH} ${LIB} -c -o $@ $<
all :
					make ${TARGET}
${TARGET} :			${OBJS}
					${CC} ${OBJS} -o ${TARGET} ${INC_PATH} ${LIB_PATH} ${LIB}
clean :
					powershell "${RM} ${BIN_DIR}/*.o"
fclean :			clean
					powershell "${RM} ${TARGET}"
re :				fclean
					make all
.PHONY :			all ${TARGET} clean fclean re