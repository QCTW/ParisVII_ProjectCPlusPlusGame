Ce framework permet de créer plusieurs types de jeux.  Jeu de serpents et échelles, jeu pédagogique, jeu à plusieurs pions et le mix des trois.

Le framework est composés de plusieurs types d'entités: cell, platform, dice, player, gameinfo et gameutils.

Plateau et Cases:
	Le plateau du jeu est representé par la classe "Platform". La "platforme" est composé d'un certain nombre de cases (cell).
	Cell (classe mère): Répresente une case du plateau. Elle possède plusieurs classe filles (EmptyCell, OrangeCell, GreenCell, SnakeHead, SnakeTail, Stair).
	- EmptyCell, represente une case vide, et ne possède aucune action particulère
	- OrangeCell, represente une case orange. Lorsqu'un pion du joueur s'arrete sur cette case, le joueur rejoue imediatent.
	- GreenCell, represente une case verte. Lorsqu'un pion du joueur s'arrete sur cette case, le joueur passe son prochain tour
	- SnakeHead, represente la tête du serpent. (Pour associer SnakeTail on appelle la methode ->addExtremety(SnakeTail *st))
	- SnakeTail, represente la queue du serpent.  (Pour associer SnakeHead on appelle la methode ->addExtremety(SnakeHead *sh))

	Pour obtenir une instance d'une case particulère on peut utiliser CellFactory puis la methode correspondante en precisant la position qu'elle aura sur le plateau.
	Ex.
		SnakeHead *sh = CellFactory::getSnakeHead(3);
		Stair *s = CellFactory::getStair(5);

	Pour obtenir une instance de plateau, on appelle directement son constructeur en précisant le nombre de cases souhaité: 
		Platform *plt = new Platform(50);

	Le plateau possède maintenant un tableau de pointeur vers "Cell" de taille 50. Ce tableau possède des pointeurs nulls.
		Pour ajouter une case au plateau il suffit d'appeler la methode add(Cell *cell);
	Ex:	
		plt->add(sh); // On vient d'ajouter la case SnakeHead à la position qui était passée en parametre

	On possède maintenant un plateau qui possède une case SnakeHead, mais le reste, ce sont des pointeurs nulls. Donc pour hydrater le plateau entierement on peut appeller la methode hydrate() du plateau qui va hydrater le plateau et remplir les cases restantes avec des EmptyCell.

	Si on souhaitez créer un plateau jouable plus rapidement, on peut directement appeler la methode hydraterWithDCells(int nbOrg, int nbGrn, int nbSnk, int nbStr). 
		Cette methode va generer les cases de facons automatique. Elle placera les cases de façons aleatoire tout en respectants les case Snakes et Staire. (SnakeTail devra toujours être placée apres la case SnakeHead et il y aura au moins une case d'écart entre les deux (pour garder l'interet des cases snake). Les cases Stair seront placé de la même façon mais avec des petites nuances).

Joueur:
	On possede deux type de joueurs. Human et AI (les deux sont des classes dérivées de Player).
	AI (Artificial Intelligence)
	Human (Human player)
	Pour obtenir une instance on peut utiliser la PlayerFactory et deux methodes statique correspondante:
		1) getHumanPlayer(string name)
		2) getIAplayer(string name, bool intelligence = true)
	AI:
		le constructeur AI possède un parametre booleen intelligence. Si on le met a "true", à chaque tour le robot choisira les pions de façons intelligente. Il choisira les pions en fonction de leur position, et déplacera d'abord les pions qui sont placés le plus loin par rapport au point d'arrivée.
		En activant le parametre intelligence, il repondra juste à toutes les questions arithmetiques posées.
		Si on met le parametre intelligence à false, il choisira les pions de facon aleatoire, et aura autant de chance de repondre juste ou faux aux questions.

	Human:
		La selection des pions et les reponses au question sont gérer par le joueur.

Move:
	Dans le move, on a deux facons pour obtenir un numero de mouvement: Dice et Cards. Pour creer l'objet, on utilise le singleton MoveFactory:

		Dice* d = MoveFactory::getInstance()->createDice(6); //Cree un de de 6
		ou
		Cards* c = MoveFactory::getInstance()->createCards(10, player1); //Cree 10 cards pour player1

Question:
	L'entité de la Question est designe pour lire un fichier au format CSV separe par semi-colon ou generer une question arithmétique automatiquement. Pour obtenir un objet de la question, on utilise le singleton QuestionFactory:

	Question* q = QuestionFactory::getInstance()->getQuestion() //Obtiens une question dans le fichier config/QCM.txt
	ou
	Question* q = QuestionFactory::getInstance()->getArithmeticsQuestion() //Genere une question arithmetique

	En suite, on peut rappeler q->getQuestion() pour la question et q->getAnswer() pour son corrige directement de l'objet Question.
	
Makefile:
	Pour compiler et mettre ensemble nos codes automatiquement, on utilise GUN make. Les commands sont suivant:

		make -> compiler et produit tout les classes.
		make clean -> effacer tout les fichiers des objets et des execution
		make test -> recompiler et executer les test

	A la fin, les fichiers des execution seront dans le dossier bin/.

GameInfo et GameUtils:
	On a la possibilté de gérer le jeu plus facilement en utilisant les classe GameInfo et GameUtils.
	GameInfo est un objet qui possède toutes les informations sur le jeux.
	Si on souhaites utiliser le framework de facon simple. Il suffit d'associer les joueurs, le dé, et le plateau à l'objet GameInfo.
	Dans le constructeur de gameinfo on doit passer le nombre de pions par jouer.
	Ex
		GameInfo *gi = new GameInfo(5); // Chacun des joueurs pourra jouer avec 5 pions
		gi->addPlatform(plt); // On associe le plateau crée précédement
		gi->addPlayer(iaPlayer); // On associe les joueurs
		gi->addPlayer(humanPlayer);
		gi->addDice(dice);


	Maintentant on peux manipuler notre jeu, c'est le rôle de GameUtils
	Pour Placer tous les pions sur le plateau et initialiser le jeux on doit appeler la methode static initializeGame(GameInfo *gi) de la classe GameUtils
	Ex:
		GameUtils::initializeGame(gi);


	Maintenant, notre jeu est initialisé. On peut commencer à jour. Pour cela on appelle la methode statique play de GameUtils
	Ex: 
		GameUtils::play(gi);
	Si on souhaitez jouer avec des question, il suffit de passer le deuxieme parametre à true.
		GameUtils::play(gi, true);
