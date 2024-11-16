-- vue entre newsletter et user

CREATE OR REPLACE VIEW user_newsletter_subscriptions AS
SELECT 
    n.id AS newsletter_id,
    u.id AS user_id,
    n.email,
    u.created_at AS user_created_at,
    n.created_at AS subscription_date
FROM newsletters n
LEFT JOIN users u ON n.email = u.email;


-- recup les traductions
SELECT JSON_OBJECT(
           'lang_code' VALUE lang_code,
           'key' VALUE key,
           'translation' VALUE translations
       ) AS json_data
FROM translations;
