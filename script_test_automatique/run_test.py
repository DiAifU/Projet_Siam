import os

dir_pgm="../bin/"
dir_test="../test/"
nom_executable="jeu_siam"
nom_etat="etat_courant.txt"

os.system("mkdir -p trace")

assert(os.path.isfile(dir_pgm+nom_executable))

all_files=[]
for root,dirs,files in os.walk(dir_test):
    for f_current in files:
        all_files.append(f_current)
    for f_current in sorted(all_files):
        if f_current.endswith(".txt"):
            name,ext=os.path.splitext(f_current)
            file_test=root+"/"+name+ext
            file_expected=root+"/"+name+"_sortie"+ext

            if os.path.isfile(file_test)==True and os.path.isfile(file_expected)==True :
                os.system("exec 2>1; "+dir_pgm+nom_executable+" < "+file_test +" > temp_sortie.txt")
                os.system("cp temp_sortie.txt trace/trace_"+f_current)
                retour_diff=os.popen("diff -i -E -b -w -B "+nom_etat+" "+file_expected).read()
                if len(retour_diff)>0:
                    print("ERREUR test "+file_test)
                    print(retour_diff)
                    exit()
                else:
                    print("OK test "+file_test)
                
                


