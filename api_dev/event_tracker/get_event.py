#from time import sleep
#import requests
#import json

#API_CLIENT_ID = "c930a6e8f8ffb6f3c041d58223158cfb00ab8e71b2783545b9f8046548d859c7"
#API_SECRET_KEY = "1f619b3cc845649edd34be3365ba8ef9e4a645ca9c2c7f2c1959d4bbf1601d37"
#authURL = "https://api.intra.42.fr/oauth/token"
#authData = {'grant_type': 'client_credentials', 'client_id': API_CLIENT_ID, 'client_secret': API_SECRET_KEY}
#r = requests.post(authURL, data = authData)
#access_token = json.loads(r.text)['access_token']

#print("ACCESS TOKEN : ")
#print(access_token)

import os
import requests
import json

API_UID = 'c930a6e8f8ffb6f3c041d58223158cfb00ab8e71b2783545b9f8046548d859c7'
API_SECRET = '1f619b3cc845649edd34be3365ba8ef9e4a645ca9c2c7f2c1959d4bbf1601d37'
API_URL = 'https://api.intra.42.fr/'

def get_oauth_token():
    url = API_URL + 'oauth/authorize'
    get_data = {
        'grant_type': 'client_credentials',
        'client_id': API_UID,
        'client_secret': API_SECRET,
        'redirect_uri' : "https://api.intra.42.fr/oauth/authorize?client_id=c930a6e8f8ffb6f3c041d58223158cfb00ab8e71b2783545b9f8046548d859c7&redirect_uri=https%3A%2F%2Fgithub.com%2FJuneParkCode&response_type=code",
        'response_type' : 'code',
        'state' : 'create+update+delete'
    }
    resp = requests.get(url, data = get_data);
    post_data = {
    }

    #resp = requests.post(url, data=post_data)
    print("returned oauth token")
    print(resp.url)
    return 0
    #return resp.json()['access_token']


def get_events(token, campus_id=None, cursus_id=None):
    url = API_URL + 'v2'
    if campus_id is not None:
        url += '/campus/' + str(campus_id)
    if cursus_id is not None:
        url += '/cursus/' + str(cursus_id)
    url += '/events'
    print(url)
    headers = {'Authorization': 'Bearer ' + token}
    resp = requests.get(url, headers=headers)
    events = json.loads(resp.text)
    print("returned event list")
    return 0

def get_user_events(token, userid):
    url = API_URL + 'v2' + '/event_users/' + userid
    headers = {'Authorization': 'Bearer ' + token}
    resp = requests.get(url, headers=headers)
    print(resp)
    events = json.loads(resp.text)
    for event in events:
        print(event['id'])
        user_event_list.append(event['id'])
    print(user_id)
    return 0
    

def register_event(event_ids):
    # 인자로 전달된 event id에 대해서 register 진행
    for event in event_ids :
        url = 'https://api.intra.42.fr/v2/events_users'
        headers = {'Authorization': 'Bearer ' + token}
        requests.post(url)
    pass

def do_program():
    while (True):
        event_id = get_event()
        if event_id:
            register_event(event_id)     
        sleep(3)
def get_myuid(token):
    url = API_URL + 'v2' + '/me'
    headers = {'Authorization': 'Bearer ' + token}
    resp = requests.get(url, headers=headers)
    print(resp)
    data = json.loads(resp.text)
    return data['id']
    

seoul_campus_id = '29'
token = get_oauth_token()
#my_uid = get_myuid(token)
#get_user_events(token, my_uid)
#get_events(token, seoul_campus_id)
