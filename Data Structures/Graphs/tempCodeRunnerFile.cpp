edges,x,y,weight,z;
    cout<<"Enter number of nodes and edges: ";
    cin>>nodes>>edges;
    int graph[nodes+1][nodes+1] = {0};

    cout<<"Enter noddes x,y and their weights: ";
    for(int i=0;i<edges;i++){
        cin>>x>>y>>weight;
        graph[x][y] = weight;
        graph[y][x] = weight;

    }