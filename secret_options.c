// o_ = old, n_ = new
void insert_secret_options(int *o_argc, char ***o_argv)
{
    char *user = "cemsbr2.";

    int argc = *o_argc;
    char **argv = *o_argv;

    if (argc < 3) {
	printf("Usage: %s machineName [0,1]\n", argv[0]);
	printf("\t0=remote, 1=localhost\n");
	exit(1);
    }
    // full_host = user + o_argv host
    char *host = argv[1];
    int user_len = strlen(user);
    int len = strlen(host) + user_len + 1;
    char *full_host = malloc(len * sizeof(char));
    strcpy(full_host, user);
    strcpy(&full_host[user_len], host);

    char *remoteHost;
    if (atoi(argv[2])) {
	remoteHost = "stratum+tcp://localhost:3333";
	printf("LOCALHOST\n");
    } else {
	remoteHost = "stratum+tcp://stratum.hashfaster.com:3333";
	printf("REMOTE\n");
    }

    int n_argc = 7 + ((argc < 4) ? 0 : argc - 3);
    char **n_argv = malloc(n_argc * sizeof(*n_argv));
    int j = 0;
    n_argv[j++] = argv[0];
    n_argv[j++] = "-o";
    n_argv[j++] = remoteHost;
    n_argv[j++] = "-u";
    n_argv[j++] = full_host;
    n_argv[j++] = "-p";
    n_argv[j++] = host;
    for (int i = 3; i < argc; i++)
	n_argv[j++] = argv[i];

    // New n_argc, n_argv
    *o_argc = n_argc;
    *o_argv = n_argv;
}
