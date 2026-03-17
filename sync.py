import os
import subprocess
import datetime

# This will find ALL .cpp files in this folder AND any subfolders
for root, dirs, files in os.walk('.'):
    for file in files:
        if file.endswith('.cpp'):
            file_path = os.path.join(root, file)
            
            # Get the file's date
            timestamp = os.path.getmtime(file_path)
            formatted_date = datetime.datetime.fromtimestamp(timestamp).strftime('%Y-%m-%d %H:%M:%S')

            print(f"Committing {file_path}...")

            # Add and Commit with the original date
            subprocess.run(['git', 'add', file_path])
            env = os.environ.copy()
            env['GIT_AUTHOR_DATE'] = formatted_date
            env['GIT_COMMITTER_DATE'] = formatted_date
            
            subprocess.run(['git', 'commit', '-m', f'Added {file}'], env=env)

print("\nFolders preserved and files committed!")